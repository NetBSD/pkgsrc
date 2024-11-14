# $NetBSD: Makefile,v 1.40 2024/11/14 14:45:01 gdt Exp $

DISTNAME=	wheel-0.45.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wheel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/wheel
COMMENT=	tool for manipulating Python wheel files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.8:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65:../../devel/py-setuptools

USE_LANGUAGES=	c # for tests only

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} wheel wheel-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
