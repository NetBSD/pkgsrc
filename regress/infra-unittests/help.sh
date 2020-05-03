#! /bin/sh
# $NetBSD: help.sh,v 1.2 2020/05/03 08:42:22 rillig Exp $
#
# Test cases for "bmake help", mainly implemented in mk/help/help.awk.
#

set -eu

. "./test.subr"

test_case_set_up() {
	cd "$tmpdir"
}


if test_case_begin "help topic at the top of a file, with debugging"; then

	# The first line of a file does not count since it usually contains
	# the CVS Id. Therefore this topic is considered too small.

	create_file_lines "test.help" \
		"# topic" \
		"#" \
		"# Explanation of the topic."

	HELP_DEBUG="yes" TOPIC=":all" awk -f "$pkgsrcdir/mk/help/help.awk" \
		"test.help" >"out"

	assert_that "out" --file-is-lines \
		'test.help:1: Adding keyword "topic"' \
		'test.help:1: Ignoring section because of too small comment.' \
		'test.help:3: "Explanation" is no keyword because it is mixed case' \
		'test.help:3: Ignoring section because of missing keywords.' \
		'No help found for :all.'

	test_case_end
fi


if test_case_begin "short help topic with debugging"; then

	# The topic starts in the paragraph in line 3 and has only 3 lines.
	# It still has enough explanation to be considered valuable.
	# This form is often used in mk/help/undefined-reference.help.

	create_file_lines "test.help" \
		"# $""NetBSD: ...$" \
		"" \
		"# topic" \
		"#" \
		"# Explanation of the topic."

	HELP_DEBUG="yes" TOPIC=":all" awk -f "$pkgsrcdir/mk/help/help.awk" \
		"test.help" >"out"

	assert_that "out" --file-is-lines \
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


if test_case_begin "short help topic"; then

	# The topic starts in the paragraph in line 3 and has only 3 lines.
	# It still has enough explanation to be considered valuable.
	# This form is often used in mk/help/undefined-reference.help.

	create_file_lines "test.help" \
		"# $""NetBSD: ...$" \
		"" \
		"# topic" \
		"#" \
		"# Explanation of the topic."

	TOPIC="topic" awk -f "$pkgsrcdir/mk/help/help.awk" \
		"test.help" >"out"

	assert_that "out" --file-is-lines \
		'===> test.help (keywords: topic):' \
		'# topic' \
		'#' \
		'# Explanation of the topic.' \

	test_case_end
fi


if test_case_begin "comments without keywords"; then

	# In the top-level Makefile, the SUBDIR section contains a few
	# comment lines, which are implementation comments and do not
	# contain keywords.  These should not appear in the help.

	create_file_lines "Makefile" \
		'SUBDIR+=	subdir1' \
		'# Comment1' \
		'# Comment2' \
		'# Comment3' \
		'SUBDIR+=	subdir2'

	TOPIC=':all' awk -f "$pkgsrcdir/mk/help/help.awk" \
		'Makefile' >"out"

	# FIXME: should be empty
	assert_that 'out' --file-is-lines \
		'===> Makefile (keywords:):' \
		'# Comment1' \
		'# Comment2' \
		'# Comment3' \
		'SUBDIR+=	subdir2'

	test_case_end
fi
