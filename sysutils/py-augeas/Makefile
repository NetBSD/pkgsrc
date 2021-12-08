# $NetBSD: Makefile,v 1.10 2021/12/08 16:06:35 adam Exp $

DISTNAME=	python-augeas-1.1.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	4
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-augeas/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://augeas.net/
COMMENT=	Python bindings for Augeas
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

do-test:
	cd ${WRKSRC}/test && ${PYTHONBIN} test_augeas.py

.include "../../sysutils/augeas/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
