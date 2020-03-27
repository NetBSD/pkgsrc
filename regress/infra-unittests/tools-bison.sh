#! /bin/sh
set -eu

# Tests for mk/tools/bison.mk

. "./test.subr"

bison=$(mock_cmd mock-bison \
	--when-args "--version" --then-output "bison 1.5"
)

pkg_admin=$(mock_cmd mock-pkg_admin \
	--when-args "pmatch bison>=1.0 bison-1.5" --then-exit 0 \
	--when-args "pmatch bison>=1.1 bison-1.5" --then-exit 0 \
	--when-args "pmatch bison>=2.0 bison-1.5" --then-exit 1
)

if test_case_begin "multiple BISON_REQD entries"; then

	# A package may add more than one entry to the BISON_REQD list. The
	# platform-provided bison may only be used if all of the BISON_REQD
	# entries are below the platform-provided version.

	create_file "multiple-reqd-entries.mk" <<EOF
BISON_REQD=		1.0 2.0
USE_TOOLS=		bison
TOOLS_PLATFORM.bison=	$tmpdir/mock-bison
ECHO=			echo
SED=			sed
PKG_ADMIN=		$tmpdir/mock-pkg_admin

all:
	@echo \${_TOOLS_USE_PKGSRC.bison}

.include "mk/tools/bison.mk"
EOF

	out=$(run_bmake "multiple-reqd-entries.mk")

	assert_that "$out" --equals "yes"

	test_case_end
fi


if test_case_begin "multiple BISON_REQD entries, both lower"; then

	# Both required versions are lower than the version of the mocked
	# bison, which is 1.5. Therefore the platform-provided bison can
	# be used.

	create_file "multiple-reqd-entries.mk" <<EOF
BISON_REQD=		1.0 1.1
USE_TOOLS=		bison
TOOLS_PLATFORM.bison=	$tmpdir/mock-bison
ECHO=			echo
SED=			sed
PKG_ADMIN=		$tmpdir/mock-pkg_admin

all:
	@echo \${_TOOLS_USE_PKGSRC.bison}

.include "mk/tools/bison.mk"
EOF

	out=$(run_bmake "multiple-reqd-entries.mk")

	assert_that "$out" --equals "no"

	test_case_end
fi
