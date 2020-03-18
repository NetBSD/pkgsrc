# $NetBSD: check-portability.awk,v 1.12 2020/03/18 17:47:40 joerg Exp $
#
# Checks a shell file for possible portability problems.
#
# ENVIRONMENT
#	(See check-subr.awk)
#

BEGIN {
	found_random = no;
	found_test_eqeq = no;
	lineno = 0;
}

# Check for $RANDOM, which is specific to ksh and bash.
function check_random(line, lineno) {

	# $RANDOM together with the PID is often found in GNU-style
	# configure scripts and is considered acceptable.
	if (line ~ /\$\$-\$RANDOM/ || line ~ /\$RANDOM-\$\$/) {
		# Assume that this is ok.

	} else if (line ~ /\$RANDOM[A-Z_]+/) {
		# That's ok, too.

	} else if (line ~ /\$RANDOM/) {
		found_random = yes;
		cs_warning_heading("Found $RANDOM:");
		cs_warning_msg(cs_fname ":" lineno ": " $0);
	}
}

function check_test_eqeq(line, lineno, n, word, i) {

	if (length(line) == 0)
		return;
	n = split(line, word);
	for (i = 3; i < n; i++) {
		if (word[i] == "==") {
			if (word[i-2] == "test" || word[i-2] == "[") {
				found_test_eqeq = yes;
				cs_error_heading("Found test ... == ...:");
				cs_error_msg(cs_fname ":" lineno ": " $0);
			}
		}
	}
}

/^$/ {
	++lineno;
}

/./ {
	# Note: This code does not find _all_ instances of
	# unportable code. If a single line contains an unsafe and
	# a safe usage of $RANDOM, it will pass the test.

	# Strip comments
	line = $0;
	gsub(/^#.*/, "", line);
	gsub(/[[:space:]]#.*/, "", line);
	++lineno;

	check_random(line, lineno);
	check_test_eqeq(line, lineno);
}

END {
	if (found_random) {
		h =   "The variable $RANDOM is not required for a POSIX-conforming shell, and\n";
		h = h "many implementations of /bin/sh do not support it. It should therefore\n";
		h = h "not be used in shell programs that are meant to be portable across a\n";
		h = h "large number of POSIX-like systems.\n"
		cs_explain(h);
	}

	if (found_test_eqeq) {
		h =   "The \"test\" command, as well as the \"[\" command, are not required to know\n";
		h = h "the \"==\" operator. Only a few implementations like bash and some\n";
		h = h "versions of ksh support it.\n";
		h = h "\n";
		h = h "When you run \"test foo == foo\" on a platform that does not support the\n";
		h = h "\"==\" operator, the result will be \"false\" instead of \"true\". This can\n";
		h = h "lead to unexpected behavior.\n";
		h = h "\n";
		h = h "There are two ways to fix this error message. If the file that contains\n";
		h = h "the \"test ==\" is needed for building the package, you should create a\n";
		h = h "patch for it, replacing the \"==\" operator with \"=\". If the file is not\n";
		h = h "needed, add its name to the CHECK_PORTABILITY_SKIP variable in the\n";
		h = h "package Makefile.\n";
		cs_explain(h);
	}

	cs_exit();
}
