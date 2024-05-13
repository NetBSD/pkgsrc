#!/usr/bin/awk -f
#
# $NetBSD: distinfo.awk,v 1.6 2024/05/13 08:08:15 wiz Exp $
#
# Copyright (c) 2007 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

###########################################################################
#
# NAME
#	distinfo.awk -- print distinfo information to standard output
#
# SYNOPSIS
#	distinfo.awk -- [options] [patch ...]
#
# DESCRIPTION
#	distinfo.awk generates distinfo information for the named
#	cksumfiles, ignorefiles and patches.  The format of a distinfo
#	file is:
#
#	   1. NetBSD RCS ID header
#	   2. a blank line
#	   3. digests and size information for each cksumfile and ignorefile
#	   4. digests for patches
#
#	For example:
#
#	$NetBSD: distinfo.awk,v 1.6 2024/05/13 08:08:15 wiz Exp $
#
#	SHA1 (make-3.81.tar.gz) = cd4fa5a3184176492bf0799593a8f250a728210c
#	RMD160 (make-3.81.tar.gz) = a713a72875cb9a29568677c98022465c6f55cbbf
#	Size (make-3.81.tar.gz) = 1564560 bytes
#	SHA1 (patch-aa) = ba88ee2175c7c2258fc647b3654b2f725cf75a50
#	SHA1 (patch-ac) = de18956fde66fa3fc61a991bb3e6724d9c5b1eac
#	SHA1 (patch-af) = 067cac366694ce33e5bc52ef937603ae17d3bc2e
#
# OPTIONS
#	The following command line arguments are supported.
#
#	--		This is a mandatory option and must always be the
#			first option specified.
#
#	-a algorithm	Generate a digest for the specified distfiles
#			using the named digest algorithm.  If this option
#			is given more than once, then digests are
#			generated using each algorithm in the order
#			given.
#
#	-c cksumfile	Generate distinfo information for the named
#			cksumfile.  If this option is given more than
#			once, then generate information for each
#			cksumfile in alphabetical order.
#
#	-d distdir	Directory under which cksumfiles and ignorefiles
#			are found.
#
#	-f distinfo	Path to an existing distinfo file.  If this
#			option is given, then it is used to provide the
#			distinfo information for either cksumfiles and
#			ignorefiles or patches, depending on which
#			are not given on the command line.  Also, using
#			this option causes the return code to be 0 if
#			the generated distinfo information matches the
#			contents of the existing distinfo file, or
#			non-zero otherwise.
#
#	-I input	Read the list of distfiles from 'input' instead
#			of the command line.
#
#	-i ignorefile	Generate distinfo information to ignore checksum
#			verification for ignorefile.  If this option is
#			given more than once, then generate information
#			for each ignore file in alphabetical order.
#
#	-p algorithm	Generate a digest for the patches using the named
#			digest algorithm.  If this option is given more
#			than once, then digests are generated using each
#			algorithm in the order given.
#
#	patch ...	Generate distinfo information for the named
#			patches in alphabetical order.
#
###########################################################################

BEGIN {
	DIGEST = ENVIRON["DIGEST"] ? ENVIRON["DIGEST"] : "digest"
	SED = ENVIRON["SED"] ? ENVIRON["SED"] : "sed"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"
	WC = ENVIRON["WC"] ? ENVIRON["WC"] : "wc"

	self = "distinfo.awk"
	ARGSTART = 1
	A = 0		# size of algorithms array
	D = 0		# size of distfiles array
	L = 0		# size of lines array
	P = 0		# size of patch_algorithms array
	N = 0		# size of patchfiles array
	F = 0		# size of distinfo_lines array

	distdir = "."
	distinfo = ""
	exitcode = 0

	parse_options()

	if (length(distdir) > 0) {
		cmd = TEST " -d " distdir
		if (system(cmd) != 0) {
			print self ": " distdir " not found"
			exitcode = 128
		}
	}
	if (length(distinfo) > 0) {
		cmd = TEST " -f " distinfo
		if (system(cmd) != 0) {
			print self ": " distinfo " not found"
			exitcode = 128
		}
		while(getline < distinfo) { distinfo_lines[F++] = $0 }
		close(distinfo)
	}

	if (exitcode > 0) exit(exitcode)

	if (length(distinfo) == 0) {		# no distinfo file
		header()
		distsum()
		patchsum()
		exitcode = 1
	} else {
		if (D > 0 && N > 0) {		# distfiles & patches
			header()
			distsum()
			patchsum()
		} else if (D > 0 && N == 0) {	# distfiles only
			header()
			distsum()
			#
			# Grab the patch distinfo lines from the existing
			# distinfo file.
			#
			for (l = 0; l < F; l++) {
				file = distinfo_lines[l]
				sub("^[^(]*[(]", "", file)
				sub("[)][^)]*$", "", file)
				if (is_patch(file))
					lines[L++] = distinfo_lines[l]
			}
		} else if (D == 0 && N > 0) {	# patches only
			#
			# Grab the non-patch distinfo lines from the
			# existing distinfo file.
			#
			for (l = 0; l < F; l++) {
				file = distinfo_lines[l]
				sub("^[^(]*[(]", "", file)
				sub("[)][^)]*$", "", file)
				if (!is_patch(file))
					lines[L++] = distinfo_lines[l]
			}
			patchsum()
		}
		exitcode = is_same_distinfo() ? 0 : 1
	}

	# Print the new distinfo content to standard output.
	for (l = 0; l < L; l++) { print lines[l] }

	exit(exitcode)
}

function insertion_sort(a, nelem,  	 temp, i, j) {
	for (i = 1; i < nelem; ++i) {
		for (j = i; a[j-1] > a[j]; --j) {
			temp = a[j]
			a[j] = a[j-1]
			a[j-1] = temp
		}
	}
	return
}

function parse_options(		option) {
	while (ARGSTART < ARGC) {
		option = ARGV[ARGSTART]
		if (option == "-a") {
			algorithms[A++] = ARGV[ARGSTART + 1]
			ARGSTART += 2
		} else if (option == "-c") {
			distfiles[D++] = ARGV[ARGSTART + 1]
			cksumfiles[ARGV[ARGSTART + 1]] = 1
			ARGSTART += 2
		} else if (option == "-d") {
			distdir = ARGV[ARGSTART + 1]
			ARGSTART += 2
		} else if (option == "-f") {
			distinfo = ARGV[ARGSTART + 1]
			ARGSTART += 2
		} else if (option == "-I") {
		    while (getline < ARGV[ARGSTART + 1]) {
			distfiles[D++] = $0
			cksumfiles[$0] = 1
		    }
		    ARGSTART += 2
		} else if (option == "-i") {
			distfiles[D++] = ARGV[ARGSTART + 1]
			ignorefiles[ARGV[ARGSTART + 1]] = 1
			ARGSTART += 2
		} else if (option == "-p") {
			patch_algorithms[P++] = ARGV[ARGSTART + 1]
			ARGSTART += 2
		} else if (option == "--") {
			ARGSTART++
			break
		} else if (match(option, /^-.*/) != 0) {
			option = substr(option, RSTART + 1, RLENGTH)
			print self ": unknown option -- " option > "/dev/stderr"
			print "usage: " self " -- [-a alg] [-c file] [-d distdir] [-f distinfo] [-I inputfile] [-i ignore] [-p alg] [patch ...]" > "/dev/stderr"
			exit 1
		} else {
			break
		}
	}
	while (ARGSTART < ARGC) {
		patchfiles[N++] = ARGV[ARGSTART++]
	}

	# Sort each of the resulting arrays.
	#insertion_sort(algorithms, A)
	#insertion_sort(patch_algorithms, P)
	insertion_sort(distfiles, D)
	insertion_sort(patchfiles, N)
}

###
###	header()
###		Pull the NetBSD RCS ID file from the existing distinfo file
###		if it's available, otherwise generate a new one.
###
function header() {
	if (length(distinfo) > 0) {
		cmd = SED " 1q " distinfo
		cmd | getline; close(cmd)
		if ($0 ~ /^[$]NetBSD/) {
			lines[L++] = $0
			lines[L++] = ""
			return
		}
	}
	lines[L++] = "$" "NetBSD" "$"
	lines[L++] = ""
}

###
###	is_patch(file)
###		Return 1 if the file is a valid patch name, or 0 otherwise.
###
function is_patch(file) {
	if (file ~ /^patch-local-|[.]orig$|[.]rej$|~$/) return 0
	if (file ~ /^patch-|^emul-.*-patch-/) return 1
	return 0
}

###
###	distsum()
###		Generate digests using the ones named in the algorithms
###		array, and size information for each cksumfile.  Generate
###		an IGNORE line for each ignorefile.
###
function distsum(		alg, file, cmd, a, i) {
	for (i = 0; i < D; i++) {
		file = distfiles[i]
		cmd = "cd " distdir " && " TEST " -f " file
		if (system(cmd) != 0) continue
		for (a = 0; a < A; a++) {
			alg = algorithms[a]
			if (cksumfiles[file] == 1) {
				cmd = "cd " distdir " && " DIGEST " " alg " " file
				cmd | getline lines[L++]; close(cmd)
			} else if (ignorefiles[file] == 1) {
				lines[L++] = alg " (" file ") = IGNORE"
			}
		}
		if (cksumfiles[file] == 1) {
			cmd = "cd " distdir " && " WC " -c " file
			cmd | getline; close(cmd)
			sub("^[ ]+", ""); sub("[ ].*", "")
			lines[L++] = "Size (" file ") = " $0 " bytes"
		}
	}
}

###
###	patchsum()
###		Generate digests using the ones named in patch_algorithms
###		for each patch.
###
function patchsum(		alg, dir, file, patch, cmd, a, i) {
	for (i = 0; i < N; i++) {
		patch = patchfiles[i]
		dir = patch; sub("/[^/]*$", "", dir)
		file = patch; sub("^.*/", "", file)
		cmd = TEST " -f " patch
		if ((system(cmd) != 0) || !is_patch(file)) continue
		for (a = 0; a < P; a++) {
			alg = patch_algorithms[a]
			cmd = SED " -e '/[$]NetBSD.*/d' " patch " | " DIGEST " " alg
			cmd | getline; close(cmd)
			sub("^", alg " (" file ") = ")
			lines[L++] = $0
		}
	}
}

###
###	is_same_distinfo()
###		Return 1 if the distinfo_lines and lines array match
###		(so the new distinfo content and the old distinfo
###		content match), and zero otherwise.
###
function is_same_distinfo(		l) {
	if (L != F) { return 0 }
	for (l = 0; l < L; l++) {
		if (distinfo_lines[l] != lines[l])
			return 0
	}
	return 1
}
