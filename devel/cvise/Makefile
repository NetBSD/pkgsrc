# $NetBSD: Makefile,v 1.29 2026/04/16 06:35:04 wiz Exp $

DISTNAME=	cvise-2.12.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=marxin/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
# git head as of 2026-04-10 supports llvm 21, so use that
GITHUB_TAG=	599de68b03d2a873687a25cb00df2ba894355016

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/marxin/cvise
COMMENT=	Super-parallel Python port of the C-Reduce
LICENSE=	modified-bsd

TOOL_DEPENDS+=	tree-sitter-cli-[0-9]*:../../textproc/tree-sitter-cli
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-pebble-[0-9]*:../../devel/py-pebble
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	c c++
USE_TOOLS+=	flex
TEST_TARGET=	test

USE_CXX_FEATURES+=	c++17

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
DEPENDS+=	unifdef-[0-9]*:../../devel/unifdef
.endif

REPLACE_PYTHON+=	cvise-cli.py
REPLACE_PYTHON+=	cvise-delta.py

.include "../../devel/cmake/build.mk"
.include "../../lang/clang/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
