# $NetBSD: Makefile,v 1.43 2025/02/23 19:38:37 wiz Exp $

DISTNAME=	wheel-0.45.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/wheel
COMMENT=	Tool for manipulating Python wheel files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65:../../devel/py-setuptools

USE_LANGUAGES=	c # for tests only

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wheel wheel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
