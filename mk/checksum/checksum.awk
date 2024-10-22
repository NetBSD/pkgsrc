#!/usr/bin/awk -f
#
# $NetBSD: checksum.awk,v 1.4 2024/10/22 06:29:21 jperkin Exp $
#
###########################################################################
#
# NAME
#	checksum.awk -- checksum files
#
# SYNOPSIS
#	checksum.awk [options] distinfo [file ...]
#
# DESCRIPTION
#	checksum will verify the checksums in the distinfo file for each
#	of the files specified.
#
#	The checksum utility exits with one of the following values:
#
#	0	All of the file checksums verify.
#
#	1	At least one of the file checksums did not match.
#
#	2	At least one of the files is missing any checksum.
#
#	>2	An error occurred.
#
# OPTIONS
#	-a algorithm	Only verify checksums for the specified algorithm.
#
#	-p		The specified files are patches, so strip out any
#			lines containing NetBSD RCS ID tags before
#			computing the checksums for verification.
#
#	-s suffix	Strip the specified suffix from the file names
#			when searching for the checksum.
#
# BUGS
#	The flow of this program is not performed in the most optimal way
#	possible, as it was deemed important to retain output compatibility
#	with the previous shell script implementation.
#

BEGIN {
	DIGEST = ENVIRON["DIGEST"] ? ENVIRON["DIGEST"] : "digest"
	SED = ENVIRON["SED"] ? ENVIRON["SED"] : "sed"

	# Retain output compatible with previous "checksum" shell script
	progname = "checksum"

	arg_count = 0
	only_alg = ""
	distinfo = ""
	exitcode = 0
	patch = 0
	suffix = ""

	for (arg = 1; arg < ARGC; arg++) {
		opt = ARGV[arg]
		if (opt == "-a") {
			only_alg = ARGV[++arg]
		} else if (opt == "-I") {
			infile = ARGV[++arg]
			while (getline < infile) {
				arg_list[arg_count++] = $0
			}
		} else if (opt == "-p") {
			patch = 1
		} else if (opt == "-s") {
			suffix = ARGV[++arg]
		} else if (opt == "--") {
			arg++
			break
		} else if (match(opt, /^-.*/) != 0) {
			opt = substr(opt, RSTART + 1, RLENGTH)
			err(sprintf("%s: unknown option -- %s", progname, opt))
			usage()
			exit 3
		} else {
			break
		}
	}

	if (arg >= ARGC) {
		usage()
		exit 3
	}

	distinfo = ARGV[arg++]
	cmd = sprintf("test -f %s", distinfo)
	if (system(cmd) != 0) {
		err(sprintf("%s: distinfo file missing: %s", progname,
		    distinfo))
		exit 3
	}

	#
	# Initialise list of files to check, passed on the command line.  In
	# order to keep things simple, distfiles[] is also used when operating
	# in patch mode (-p).
	#
	while (arg < ARGC) {
		arg_list[arg_count++] = ARGV[arg++]
	}
	i = 0
	while (i < arg_count) {
		distfile = arg_list[i++]
		sfile = distfile
		if (suffix) {
			sfile = strip_suffix(sfile)
		}
		if (patch) {
			gsub(/.*\//, "", sfile)
		}

		#
		# Have we seen this file in distinfo?  Used later to verify
		# that all checksums have been recorded.
		#
		seen[sfile] = 0

		#
		# Store the filename to be checked in the distinfo file.  The
		# -s flag allows temporary download files to be tested instead,
		# where the suffix will be stripped to match distinfo.
		#
		distfiles[sfile] = distfile
	}

	#
	# Parse the distinfo file for checksums that must be verified.  We're
	# only interested in lines of the format:
	#
	#	algorithm (distfile) = checksum
	#
	while (getline < distinfo) {
		if (NF != 4) {
			continue
		}
		if ($0 ~ /^(#|\$|Size)/) {
			continue
		}

		algorithm = $1
		# strip "(filename)" -> "filename"
		distfile = substr($2, 2, (length($2) - 2))
		checksum = $4

		# Skip IGNORE lines (likely legacy at this point).
		if (checksum == "IGNORE") {
			continue
		}

		# If -a is set then skip non-matching algorithms.
		if (only_alg && tolower(algorithm) != tolower(only_alg)) {
			continue
		}

		# Skip if file not in distfiles.
		if (!(distfile in distfiles)) {
			continue
		}

		#
		# Handle patch files inline.  As they need to be modified (by
		# removing the NetBSD RCD Id) they are parsed individually by
		# digest(1), and so we calculate the checksums now rather than
		# saving for later processing to simplify things.
		#
		if (patch) {
			patchfile = distfiles[distfile]
			cmd = sprintf("%s -e '/[$]NetBSD.*/d' %s | %s %s",
			    SED, patchfile, DIGEST, algorithm)
			while ((cmd | getline) > 0) {
				checksums[algorithm, distfile] = $1
			}
			close(cmd)
			continue
		}

		#
		# Due to command line argument limits we sometimes need to
		# split commands up.  Store a count for each algorithm, which
		# also serves as a way to iterate over all of the algorithms
		# we've encountered.
		#
		if (!batch[algorithm]) {
			batch[algorithm] = 0
		}

		#
		# If not a patch file, then we're handling a distfile, where we
		# want to build a list of input files to digest(1) so they can
		# all be calculated in one go.
		#
		# Increase the batch number if over 64K.  This is well below the
		# limits seen in the wild (e.g. NetBSD at 256K), but there are
		# very minimal improvements above this threshold in testing.
		#
		b = batch[algorithm]
		if (length(distsums[algorithm,b]) > 65536) {
			batch[algorithm] = ++b
		}
		distsums[algorithm,b] = sprintf("%s %s", distsums[algorithm,b],
		    distfiles[distfile])
	}
	close(distinfo)

	#
	# We now have a list of distfiles to be checked for each algorithm,
	# pass them all to a single digest(1) command and parse the checksums
	# to be compared against distinfo.
	#
	for (algorithm in batch) {
		for (b = 0; b <= batch[algorithm]; b++) {
			cmd = sprintf("%s %s %s", DIGEST, algorithm,
			    distsums[algorithm,b])
			while ((cmd | getline) > 0) {
				# Should be unnecessary, but just in case.  If
				# we want to be really paranoid then test that
				# $1 == algorithm.
				if (NF != 4) {
					continue
				}
				# strip "(filename)" -> "filename"
				distfile = substr($2, 2, length($2) - 2)
				if (suffix) {
					distfile = strip_suffix(distfile)
				}
				checksums[$1, distfile] = $4
			}
			close(cmd)
		}
	}

	#
	# Now that we have computed all the necessary checksums for all of the
	# files listed on the command line, go back through distinfo and verify
	# that they all match.
	#
	while (getline < distinfo) {
		if (NF != 4) {
			continue
		}
		if ($0 ~ /^(#|\$|Size)/) {
			continue
		}

		algorithm = $1
		# strip "(filename)" -> "filename"
		distfile = substr($2, 2, (length($2) - 2))
		checksum = $4

		# If -a is set then skip non-matching algorithms.
		if (only_alg && tolower(algorithm) != tolower(only_alg)) {
			continue
		}

		# Skip if file not in distfiles.
		if (!(distfile in distfiles)) {
			continue
		}

		# This is likely very legacy at this point.
		if (checksum == "IGNORE") {
			err(sprintf("%s: Ignoring checksum for %s", progname,
			    distfile))
			continue
		}

		if (checksums[algorithm,distfile] == checksum) {
			printf("=> Checksum %s OK for %s\n", algorithm,
			    distfile)
			seen[distfile] = 1
		} else {
			err(sprintf("%s: Checksum %s mismatch for %s",
			    progname, algorithm, distfile))
			exit 1
		}
	}
	close(distinfo)

	#
	# Check that all distfiles supplied on the command line have at least
	# one matching checksum.
	#
	for (distfile in distfiles) {
		if (seen[distfile])
			continue

		if (only_alg) {
			err(sprintf("%s: No %s checksum recorded for %s",
			    progname, only_alg, distfile))
		} else {
			err(sprintf("%s: No checksum recorded for %s",
			    progname, distfile))
		}
		exitcode = 2
	}

	exit(exitcode)
}

function err(errmsg)
{
	printf("%s\n", errmsg) > "/dev/stderr"
}

function usage()
{
	err(sprintf("usage: %s [-a algorithm] [-p] [-s suffix]" \
		    " distinfo [file ...]", progname))
}

#
# In order to provide maximum compatibility, the following function attempts
# to strip the exact string suffix, rather than a simple sub() which may
# interpret e.g. dots incorrectly as it uses regular expressions.
#
# "suffix" is a global variable, and this function is only called when it is
# set.
#
function strip_suffix(filename)
{
	len_file = length(filename)
	len_sufx = length(suffix)
	len_s1 = len_file - len_sufx

	if (len_s1 <= 0)
		return filename

	s1 = substr(filename, 1, len_s1)
	s2 = substr(filename, len_s1 + 1, len_sufx)

	if (s2 == suffix) {
		return s1
	} else {
		return filename
	}
}
