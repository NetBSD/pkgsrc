#! /bin/sh
set -eu

# Ensures that files that are overridden in the "mocked pkgsrc" directory
# are picked up before those from the "real pkgsrc" directory.

. "./test.subr"

if test_case_begin "mock"; then

	create_file_lines "including.mk" \
		'.include "mk/bsd.prefs.mk"'

	create_pkgsrc_file "mk/bsd.prefs.mk" <<EOF
all:
	@echo 'the mocked definition wins'
EOF

	out=$(test_file "including.mk")

	assert_that "$out" --equals "the mocked definition wins"

	test_case_end
fi
