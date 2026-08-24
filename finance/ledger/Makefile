# $NetBSD: Makefile,v 1.48 2026/08/24 08:42:18 adam Exp $

DISTNAME=	ledger-3.4.1
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=ledger/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	https://ledger-cli.org/
COMMENT=	Double-entry accounting system for command-line
LICENSE=	modified-bsd

CONFLICTS+=	ledger32>=0

USE_CXX_FEATURES+=	c++17

USE_LANGUAGES=	c c++
USE_TOOLS+=	perl:run

TEST_TARGET=	check
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC:Q}/${CMAKE_BUILD_DIR:Q}
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC:Q}/${CMAKE_BUILD_DIR:Q}

CMAKE_CONFIGURE_ARGS+=	-DPython_EXECUTABLE:STRING=${TOOL_PYTHONBIN:Q}

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "options.mk"

REPLACE_PYTHON+=	acprep
REPLACE_PYTHON+=	contrib/getquote-uk.py
REPLACE_PYTHON+=	contrib/ledger-du
REPLACE_PYTHON+=	contrib/non-profit-audit-reports/csv2ods.py
REPLACE_PYTHON+=	contrib/non-profit-audit-reports/readcsv.py
REPLACE_PYTHON+=	python/demo.py
REPLACE_PYTHON+=	test/DocTests.py
REPLACE_PYTHON+=	test/LedgerHarness.py
REPLACE_PYTHON+=	test/RegressTests.py
REPLACE_PYTHON+=	test/convert.py
REPLACE_PYTHON+=	tools/genuuid

REPLACE_PERL+=		contrib/getquote.pl
REPLACE_PERL+=		contrib/non-profit-audit-reports/*.plx
REPLACE_PERL+=		contrib/raw/GenerateLatexExpeneseReport.pl

REPLACE_SH+=		contrib/repl.sh

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/editline/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../textproc/utf8-cpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
