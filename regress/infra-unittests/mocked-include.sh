#! /bin/sh
# $NetBSD: mocked-include.sh,v 1.4 2020/04/26 12:46:33 rillig Exp $
#
# Demonstrates how to mock a pkgsrc infrastructure file in a regression
# test.  This mocked file is created using create_pkgsrc_file and
# overrides any file of the same name from the "real pkgsrc" directory.
#

set -eu

. "./test.subr"

if test_case_begin "mock"; then

	create_file_lines "including.mk" \
		'.include "mk/bsd.prefs.mk"'

	create_pkgsrc_file "mk/bsd.prefs.mk" <<EOF
all:
	@echo 'the mocked definition wins'
EOF

	out=$(run_bmake "including.mk")

	assert_that "$out" --equals "the mocked definition wins"

	test_case_end
fi
