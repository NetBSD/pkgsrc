# $NetBSD: Makefile,v 1.5 2024/03/06 21:58:17 wiz Exp $

DISTNAME=	trrntzip-1.3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=0-wiz-0/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/0-wiz-0/trrntzip/
COMMENT=	Create zip archives in a standard format
LICENSE=	gnu-gpl-v2 AND zlib

# TEST_DEPENDS, but checked for during cmake configuration
TOOL_DEPENDS+=	${PYPKGPREFIX}-nihtest-[0-9]*:../../devel/py-nihtest

TEST_TARGET=	test

pre-configure:
	${LN} -fs ${PREFIX}/bin/nihtest-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/nihtest

.include "../../lang/python/tool.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
