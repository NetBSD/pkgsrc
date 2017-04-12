# $NetBSD: Makefile,v 1.4 2017/04/12 11:40:08 adam Exp $

DISTNAME=	greenlet-0.4.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/greenlet/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/python-greenlet/greenlet
COMMENT=	Lightweight in-process concurrent programming
LICENSE=	mit

USE_LANGUAGES=	c c++

#BUILD_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
#BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
#BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

#do-test:
#	cd ${WRKSRC} && tox

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
