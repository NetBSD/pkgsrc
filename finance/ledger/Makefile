# $NetBSD: Makefile,v 1.37 2024/10/10 21:47:00 wiz Exp $

DISTNAME=	ledger-3.3.2
PKGREVISION=	7
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_GITHUB:=ledger/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	base@atomicules.co.uk
HOMEPAGE=	https://ledger-cli.org/
COMMENT=	Double-entry accounting system for command-line
LICENSE=	modified-bsd

CONFLICTS+=	ledger32>=0

USE_CXX_FEATURES+=	c++11

USE_LANGUAGES=	c c++
TEST_TARGET=	check

# https://github.com/ledger/ledger/issues/2332
PYTHON_VERSIONS_ACCEPTED=	310 311	# PyUnicode_GET_SIZE

CMAKE_CONFIGURE_ARGS+=	-DPython_EXECUTABLE:STRING=${TOOL_PYTHONBIN:Q}

.include "options.mk"

REPLACE_PYTHON+=	contrib/getquote-uk.py
REPLACE_PYTHON+=	acprep
REPLACE_PYTHON+=	python/demo.py
REPLACE_PYTHON+=	test/DocTests.py
REPLACE_PYTHON+=	test/LedgerHarness.py
REPLACE_PYTHON+=	test/RegressTests.py
REPLACE_PYTHON+=	test/convert.py
REPLACE_PYTHON+=	tools/genuuid

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
