# $NetBSD: Makefile,v 1.32 2026/10/07 07:44:30 wiz Exp $

DISTNAME=	lcov-2.6
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=linux-test-project/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
PATCHFILES+=	af02b08f844200aa3ee611062036499f652520d0.diff
PATCH_SITES=	https://github.com/henry2cox/lcov/commit/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	https://github.com/linux-test-project/lcov
COMMENT=	Front-end for GCC's coverage testing tool gcov
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme-[0-9]*:../../textproc/py-sphinx-rtd-theme
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Devel-Cover-[0-9]*:../../devel/p5-Devel-Cover
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-W3CDTF-[0-9]*:../../time/p5-DateTime-Format-W3CDTF
DEPENDS+=	p5-GD-[0-9]*:../../graphics/p5-GD
DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS
DEPENDS+=	p5-Memory-Process-[0-9]*:../../sysutils/p5-Memory-Process
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-xlsxwriter>=0:../../textproc/py-xlsxwriter
TEST_DEPENDS+=	jq-[0-9]*:../../devel/jq

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:run gmake perl

USE_CXX_FEATURES=	c++20
# needs compiler features from 14.2
GCC_REQD+=		14

BUILD_TARGET=	doc xs_lib

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	SPHINXBUILD=${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX}
MAKE_FLAGS+=	MAN_DIR=${PREFIX}/${PKGMANDIR}
MAKE_FLAGS+=	CFG_INST_DIR=${DESTDIR}${PREFIX}/share/examples/lcov

CONF_FILES=	${PREFIX}/share/examples/lcov/lcovrc \
		${PKG_SYSCONFDIR}/lcovrc

# as of 2.6nb4:
# 91 tests executed, 91 passed, 0 failed, 0 skipped
TEST_TARGET=	test
# breaks tests
#TEST_ENV+=	TESTCASE_ARGS=--parallel\ ${_MAKE_JOBS_N:U1}

REPLACE_BASH+=	bin/checkstyle.sh
REPLACE_BASH+=	bin/copy_dates.sh
REPLACE_BASH+=	bin/get_changes.sh
REPLACE_BASH+=	bin/get_version.sh
REPLACE_BASH+=	example/java_avail.sh
REPLACE_BASH+=	tests/bin/test_run
REPLACE_BASH+=	tests/bin/test_skip
REPLACE_BASH+=	tests/bin/testsuite_exit
REPLACE_BASH+=	tests/bin/testsuite_init
REPLACE_BASH+=	tests/genhtml/counts/counts.sh
REPLACE_BASH+=	tests/genhtml/criteria/criteria.sh
REPLACE_BASH+=	tests/genhtml/demangle.sh
REPLACE_BASH+=	tests/genhtml/diffread/diffread.sh
REPLACE_BASH+=	tests/genhtml/errs/msgtest1.sh
REPLACE_BASH+=	tests/genhtml/errs/msgtest2.sh
REPLACE_BASH+=	tests/genhtml/errs/msgtest3.sh
REPLACE_BASH+=	tests/genhtml/errs/msgtest4.sh
REPLACE_BASH+=	tests/genhtml/errs/select.sh
REPLACE_BASH+=	tests/genhtml/exception/exception.sh
REPLACE_BASH+=	tests/genhtml/full.sh
REPLACE_BASH+=	tests/genhtml/function/function.sh
REPLACE_BASH+=	tests/genhtml/htmlgen/htmlgen.sh
REPLACE_BASH+=	tests/genhtml/insensitive/insensitive.sh
REPLACE_BASH+=	tests/genhtml/lambda/lambda.sh
REPLACE_BASH+=	tests/genhtml/lcovrc/lcovrc.sh
REPLACE_BASH+=	tests/genhtml/mycppfilt.sh
REPLACE_BASH+=	tests/genhtml/part1.sh
REPLACE_BASH+=	tests/genhtml/part2.sh
REPLACE_BASH+=	tests/genhtml/relative/relative.sh
REPLACE_BASH+=	tests/genhtml/selectscript/selectscript.sh
REPLACE_BASH+=	tests/genhtml/shellquote/shellquote.sh
REPLACE_BASH+=	tests/genhtml/simple/part1.sh
REPLACE_BASH+=	tests/genhtml/simple/part2.sh
REPLACE_BASH+=	tests/genhtml/simple/part3.sh
REPLACE_BASH+=	tests/genhtml/simple/part4.sh
REPLACE_BASH+=	tests/genhtml/simple/part5.sh
REPLACE_BASH+=	tests/genhtml/synthesize/synthesize.sh
REPLACE_BASH+=	tests/genhtml/target.sh
REPLACE_BASH+=	tests/genhtml/xplatform/xplatform.sh
REPLACE_BASH+=	tests/genhtml/zero.sh
REPLACE_BASH+=	tests/genpng/genpng.sh
REPLACE_BASH+=	tests/html2lcov/html2lcov.sh
REPLACE_BASH+=	tests/lcov/add/aggdir.sh
REPLACE_BASH+=	tests/lcov/add/prune.sh
REPLACE_BASH+=	tests/lcov/add/track.sh
REPLACE_BASH+=	tests/lcov/branch/branch.sh
REPLACE_BASH+=	tests/lcov/coverage/coverage.sh
REPLACE_BASH+=	tests/lcov/coverage/geninfo.sh
REPLACE_BASH+=	tests/lcov/errs/errs.sh
REPLACE_BASH+=	tests/lcov/exception/exception.sh
REPLACE_BASH+=	tests/lcov/extract/extract1.sh
REPLACE_BASH+=	tests/lcov/extract/extract2.sh
REPLACE_BASH+=	tests/lcov/follow/follow.sh
REPLACE_BASH+=	tests/lcov/format/format.sh
REPLACE_BASH+=	tests/lcov/gcov-tool/mygcov.sh
REPLACE_BASH+=	tests/lcov/initializer/initializer.sh
REPLACE_BASH+=	tests/lcov/lambda/lambda.sh
REPLACE_BASH+=	tests/lcov/mcdc/mcdc.sh
REPLACE_BASH+=	tests/lcov/merge/merge.sh
REPLACE_BASH+=	tests/lcov/misc/help.sh
REPLACE_BASH+=	tests/lcov/misc/language.sh
REPLACE_BASH+=	tests/lcov/misc/profile.sh
REPLACE_BASH+=	tests/lcov/misc/split_char.sh
REPLACE_BASH+=	tests/lcov/misc/version.sh
REPLACE_BASH+=	tests/lcov/misc/zerocounters.sh
REPLACE_BASH+=	tests/lcov/multiple/multiple.sh
REPLACE_BASH+=	tests/lcov/names/names.sh
REPLACE_BASH+=	tests/lcov/parallel_fail/parallel_fail.sh
REPLACE_BASH+=	tests/lcov/parallel_parse/parallel_parse.sh
REPLACE_BASH+=	tests/lcov/serialization/binary.sh
REPLACE_BASH+=	tests/lcov/serialization/format.sh
REPLACE_BASH+=	tests/lcov/summary/concatenated.sh
REPLACE_BASH+=	tests/lcov/summary/concatenated2.sh
REPLACE_BASH+=	tests/lcov/summary/full.sh
REPLACE_BASH+=	tests/lcov/summary/part1.sh
REPLACE_BASH+=	tests/lcov/summary/part2.sh
REPLACE_BASH+=	tests/lcov/summary/target.sh
REPLACE_BASH+=	tests/lcov/summary/zero.sh
REPLACE_BASH+=	tests/lcov/tempdir/tempdir.sh
REPLACE_BASH+=	tests/lcov/xplatform/xplatform.sh
REPLACE_BASH+=	tests/lcov/xs_test/xs1.sh
REPLACE_BASH+=	tests/lcov/xs_test/xs2.sh
REPLACE_BASH+=	tests/lcov/xs_test/xs3.sh
REPLACE_BASH+=	tests/lcov/xs_test/xs4.sh
REPLACE_BASH+=	tests/lcov/xs_test/xs5.sh
REPLACE_BASH+=	tests/lcov/xs_test/xs6.sh
REPLACE_BASH+=	tests/lcov/xs_test/xs7.sh
REPLACE_BASH+=	tests/llvm2lcov/llvm2lcov.sh
REPLACE_BASH+=	tests/llvm2lcov/malformed.sh
REPLACE_BASH+=	tests/perl2lcov/perltest1.sh
REPLACE_BASH+=	tests/py2lcov/py2lcov.sh
REPLACE_BASH+=	tests/scripts/analyzeInfoFiles_test.sh
REPLACE_BASH+=	tests/scripts/annotateutil_test.sh
REPLACE_BASH+=	tests/scripts/batchgitversion_test.sh
REPLACE_BASH+=	tests/scripts/get_signature_test.sh
REPLACE_BASH+=	tests/scripts/gitblame_test.sh
REPLACE_BASH+=	tests/scripts/gitdiff_test.sh
REPLACE_BASH+=	tests/scripts/gitversion_test.sh
REPLACE_BASH+=	tests/scripts/p4annotate_test.sh
REPLACE_BASH+=	tests/scripts/p4udiff_test.sh
REPLACE_BASH+=	tests/scripts/p4version_test.sh
REPLACE_BASH+=	tests/xml2lcov/xml2lcov.sh

# these scripts are generating other scripts, so more lines need changing
SUBST_CLASSES+=		bh
SUBST_SED.bh+=		-e "s,/bin/bash,/usr/pkg/bin/bash,"
SUBST_FILES.bh+=	tests/genhtml/scriptargs/scriptargs.sh
SUBST_FILES.bh+=	tests/jacoco2lcov/jacoco2lcov.sh
SUBST_FILES.bh+=	tests/lcov/demangle/demangle.sh
SUBST_FILES.bh+=	tests/lcov/gcov-tool/path.sh
SUBST_FILES.bh+=	tests/lcov/scheduling/scheduling.sh
SUBST_FILES.bh+=	tests/perl2lcov/declforms.sh
SUBST_FILES.bh+=	tests/winpath/winpath.sh
SUBST_STAGE.bh=		pre-configure
SUBST_MESSAGE.bh=	Fixing path to bash.

SUBST_CLASSES+=		pyc
SUBST_SED.pyc+=		-e "s,cover_cmd = 'coverage,cover_cmd = 'coverage-${PYVERSSUFFIX},"
SUBST_SED.pyc+=		-e "s,command -v coverage,command -v coverage-${PYVERSSUFFIX},"
SUBST_SED.pyc+=		-e 's,echo "coverage",echo "coverage-'${PYVERSSUFFIX}'",'
SUBST_FILES.pyc+=	bin/py2lcov
SUBST_FILES.pyc+=	tests/common.tst
SUBST_STAGE.pyc=	pre-configure
SUBST_MESSAGE.pyc=	Fixing py-coverage binary name.

REPLACE_PERL+=	bin/fix.pl
REPLACE_PERL+=	bin/gendesc
REPLACE_PERL+=	bin/genhtml
REPLACE_PERL+=	bin/geninfo
REPLACE_PERL+=	bin/genpng
REPLACE_PERL+=	bin/html2lcov
REPLACE_PERL+=	bin/jacoco2lcov
REPLACE_PERL+=	bin/lcov
REPLACE_PERL+=	bin/llvm2lcov
REPLACE_PERL+=	bin/perl2lcov
REPLACE_PERL+=	scripts/*.pm
REPLACE_PERL+=	scripts/analyzeInfoFiles
REPLACE_PERL+=	scripts/criteria
REPLACE_PERL+=	scripts/get_signature
REPLACE_PERL+=	scripts/getp4version
REPLACE_PERL+=	scripts/gitblame
REPLACE_PERL+=	scripts/gitdiff
REPLACE_PERL+=	scripts/gitversion
REPLACE_PERL+=	scripts/p4annotate
REPLACE_PERL+=	scripts/p4udiff
REPLACE_PERL+=	tests/bin/check_counts
REPLACE_PERL+=	tests/bin/checkdeps
REPLACE_PERL+=	tests/bin/mkinfo
REPLACE_PERL+=	tests/genhtml/errs/MsgContext.pm
REPLACE_PERL+=	tests/genhtml/errs/genError.pm
REPLACE_PERL+=	tests/genhtml/errs/missingRestore.pm
REPLACE_PERL+=	tests/genhtml/errs/parallelFail.pm
REPLACE_PERL+=	tests/genhtml/filter/filter.pl
REPLACE_PERL+=	tests/genhtml/htmlgen/annotate.pl
REPLACE_PERL+=	tests/genhtml/insensitive/annotate.pl
REPLACE_PERL+=	tests/genhtml/insensitive/version.pl
REPLACE_PERL+=	tests/genhtml/lcovrc/annotate.pl
# not a shebang line, so REPLACE_PERL doesn't work
#REPLACE_PERL+=	tests/genhtml/selectscript/selectscript.sh
REPLACE_PERL+=	tests/genhtml/simple/annotate.pl
REPLACE_PERL+=	tests/genpng/dumppng.pl
REPLACE_PERL+=	tests/lcov/demangle/simplify.pl
REPLACE_PERL+=	tests/lcov/extract/brokenCallback.pm
REPLACE_PERL+=	tests/lcov/fork_throttle/fork_throttle.pl
REPLACE_PERL+=	tests/lcov/parallel_parse/gen_info.pl

REPLACE_PYTHON+=	bin/py2lcov
REPLACE_PYTHON+=	bin/xml2lcov
REPLACE_PYTHON+=	bin/xml2lcovutil.py
REPLACE_PYTHON+=	scripts/*.py
REPLACE_PYTHON+=	tests/bin/cleantests.py
REPLACE_PYTHON+=	tests/bin/common.py
REPLACE_PYTHON+=	tests/bin/runtests.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_parallelism.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_peakmem_columns.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_scalar_row.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_summary_refs.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_table_column.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_table_index.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_table_layout.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_thresholds.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_value_list.py
REPLACE_PYTHON+=	tests/lcov/scheduling/check_xs_row.py
REPLACE_PYTHON+=	tests/py2lcov/test.py

# clang wrappers confuse the test script
pre-configure:
	${RM} ${WRAPPER_BINDIR}/clang
	${RM} ${WRAPPER_BINDIR}/clang++
	${RM} ${WRAPPER_BINDIR}/clang-cpp

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/lcov/tests/common.tst.orig
	${RM} -f ${DESTDIR}${PREFIX}/share/lcov/tests/lcov/extract/extract2.sh.orig
	${FIND} ${DESTDIR}${PREFIX} -name *.orig_dist -delete

.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
