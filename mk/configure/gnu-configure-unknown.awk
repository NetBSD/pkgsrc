#! awk
# $NetBSD: gnu-configure-unknown.awk,v 1.1 2019/05/04 15:16:50 rillig Exp $
#
# Inspects all GNU configure scripts from a package, including nested
# ones, to see whether command line options that are reported as
# unrecognized by one of them are also unrecognized by the others.
#
# See GNU_CONFIGURE_STRICT.

BEGIN {
	# The set of all options from all configure scripts,
	# kept in insertion order to guarantee reproducible output.
	delete opts; opts_len = 0; delete opts_seen;

	# The list of subdirectories from which a configure script
	# has been executed.
	delete subdirs; subdirs_len = 0;

	# There's always at least one configure script.
	# This script may execute others.
	subdir = ".";
	subdirs[subdirs_len++] = subdir;
}

/^=== configuring in / {
	subdir = $4;
	subdirs[subdirs_len++] = subdir;
}

/^configure: WARNING: unrecognized options: / {
	for (i = 5; i <= NF; i++) {
		opt = $i;
		sub(",", "", opt);
		if (!opts_seen[opt]++) {
			opts[opts_len++] = opt;
		}
		unknown[subdir, opt] = 1;
	}
}

function count_unknown(opt,   n, i) {
	n = 0;
	for (i in subdirs) {
		if (unknown[subdirs[i], opt]) {
			n++;
		}
	}
	return n;
}

function summary(opt,   n) {
	n = count_unknown(opt);
	if (n == subdirs_len) {
		print("option " opt " is unknown",
			"in all " subdirs_len " configure scripts");
		return 1;
	}

	if ("PKG_VERBOSE" in ENVIRON) {
		print("good: option " opt " is known",
			"in " (subdirs_len - n),
			"of " subdirs_len " configure scripts");
		return 1;
	}

	return 0;
}

function finish(_,   i, msgs) {
	msgs = 0;
	for (i = 0; i < opts_len; i++) {
		msgs += summary(opts[i]);
	}

	if (msgs == 0) {
		print("good: all " opts_len " options are used somewhere");
		print("please set GNU_CONFIGURE_STRICT=no in the package");
	}
}

END {
	finish()
}
