# $NetBSD: Makefile,v 1.2 2024/04/30 11:24:26 wiz Exp $

DISTNAME=	pip2pi-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip2pi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wolever/pip2pi/
COMMENT=	Build a PyPI-compatible package repository from pip
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bins in dir2pi pip2pi pip2tgz
	${MV} ${DESTDIR}${PREFIX}/bin/${bins} ${DESTDIR}${PREFIX}/bin/${bins}-${PYVERSSUFFIX}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
