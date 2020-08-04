#! /bin/sh
# $NetBSD: help.sh,v 1.7 2020/08/04 21:46:44 rillig Exp $
#
# Test cases for "bmake help", mainly implemented in mk/help/help.awk.
#

set -eu

. './test.subr'

test_case_set_up() {
	cd "$tmpdir"
}


if test_case_begin 'help topic at the top of a file, with debugging'; then

	# The first line of a file does not count since it usually contains
	# the CVS Id. Therefore this topic is considered too small.

	create_file_lines 'test.help' \
		'# topic' \
		'#' \
		'# Explanation of the topic.'

	HELP_DEBUG='yes' TOPIC=':all' awk -f "$pkgsrcdir/mk/help/help.awk" \
		'test.help' >'out'

	assert_that 'out' --file-is-lines \
		'test.help:1: Adding keyword "topic"' \
		'test.help:1: Ignoring section because of too small comment.' \
		'test.help:3: "Explanation" is no keyword because it is mixed case' \
		'test.help:3: Ignoring section because of missing keywords.' \
		'No help found for :all.'

	test_case_end
fi


if test_case_begin 'short help topic with debugging'; then

	# The topic starts in the paragraph in line 3 and has only 3 lines.
	# It still has enough explanation to be considered valuable.
	# This form is often used in mk/help/undefined-reference.help.

	create_file_lines 'test.help' \
		'# $''NetBSD: ...$' \
		'' \
		'# topic' \
		'#' \
		'# Explanation of the topic.'

	HELP_DEBUG='yes' TOPIC=':all' awk -f "$pkgsrcdir/mk/help/help.awk" \
		'test.help' >'out'

	assert_that 'out' --file-is-lines \
		'test.help:1: "$NetBSD:" is no keyword because it is mixed case' \
		'test.help:1: Ignoring section because of missing keywords.' \
		'test.help:2: Ignoring section because of missing keywords.' \
		'test.help:3: Adding keyword "topic"' \
		'test.help:5: "Explanation" is no keyword because it is mixed case' \
		'===> test.help (keywords: topic):' \
		'# topic' \
		'#' \
		'# Explanation of the topic.' \

	test_case_end
fi


if test_case_begin 'short help topic'; then

	# The topic starts in the paragraph in line 3 and has only 3 lines.
	# It still has enough explanation to be considered valuable.
	# This form is often used in mk/help/undefined-reference.help.

	create_file_lines 'test.help' \
		'# $''NetBSD: ...$' \
		'' \
		'# topic' \
		'#' \
		'# Explanation of the topic.'

	TOPIC='topic' awk -f "$pkgsrcdir/mk/help/help.awk" \
		'test.help' >'out'

	assert_that 'out' --file-is-lines \
		'===> test.help (keywords: topic):' \
		'# topic' \
		'#' \
		'# Explanation of the topic.' \

	test_case_end
fi


if test_case_begin 'comments without keywords'; then

	# In the top-level Makefile, the SUBDIR section contains a few
	# comment lines, which are implementation comments and do not
	# contain keywords.  These should not appear in the help.

	create_file_lines 'Makefile' \
		'SUBDIR+=	subdir1' \
		'# Comment1' \
		'# Comment2' \
		'# Comment3' \
		'SUBDIR+=	subdir2'

	TOPIC=':all' awk -f "$pkgsrcdir/mk/help/help.awk" \
		'Makefile' >'out'

	assert_that 'out' --file-is-lines \
		'No help found for :all.'

	test_case_end
fi


if test_case_begin 'commented variables with continuation lines'; then

	# When a variable assignment is commented out, it can still
	# contain continuation lines.  These are not ordinary comments
	# and therefore do not count to the minimum number of comment
	# lines.
	#
	# Found in mk/defaults/mk.conf.

	create_file_lines 'mk.conf' \
		'# Australia.' \
		'#' \
		'#MASTER_SITE_OPENOFFICE=	... \' \
		'#				... \' \
		'#				...' \
		'#'

	TOPIC=':all' awk -f "$pkgsrcdir/mk/help/help.awk" \
		'mk.conf' >'out'

	assert_that 'out' --file-is-lines \
		'No help found for :all.'

	test_case_end
fi


if test_case_begin 'variable name followed by comma'; then

	create_file 'fetch.mk' <<-EOF
		#
		# FETCH_USE_IPV4_ONLY, if defined, will ...
		#	...
		#	...
	EOF

	TOPIC='fetch_use_ipv4_only' awk -f "$pkgsrcdir/mk/help/help.awk" \
		'fetch.mk' >'out'

	assert_that 'out' --file-is-lines \
		'===> fetch.mk (keywords: FETCH_USE_IPV4_ONLY):' \
		'# FETCH_USE_IPV4_ONLY, if defined, will ...' \
		'#	...' \
		'#	...'

	test_case_end
fi
