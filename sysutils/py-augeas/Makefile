# $NetBSD: Makefile,v 1.23 2025/04/17 21:52:28 wiz Exp $

DISTNAME=	python-augeas-1.1.0
PKGNAME=	${DISTNAME:S/python/${PYPKGPREFIX}/}
PKGREVISION=	16
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-augeas/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	http://augeas.net/
COMMENT=	Python bindings for Augeas
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.0.0:../../devel/py-cffi

do-test:
	cd ${WRKSRC}/test && ${PYTHONBIN} test_augeas.py

.include "../../sysutils/augeas/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
