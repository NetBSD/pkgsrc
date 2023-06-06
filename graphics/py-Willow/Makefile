# $NetBSD: Makefile,v 1.15 2023/06/06 08:02:13 wiz Exp $

DISTNAME=	Willow-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=W/Willow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/Willow
COMMENT=	Wrapper library for Pillow, OpenCV and Wand
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.1.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.1.1:../../sysutils/py-filetype
DEPENDS+=	${PYPKGPREFIX}-wand>=0.6:../../graphics/py-wand
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=3.0.0:../../devel/py-mock

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest tests/*.py

.include "../../graphics/opencv/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
