# $NetBSD: Makefile,v 1.4 2025/04/12 19:43:14 adam Exp $

DISTNAME=	pip2pi-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip2pi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wolever/pip2pi/
COMMENT=	Build a PyPI-compatible package repository from pip
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip

post-install:
.for bins in dir2pi pip2pi pip2tgz
	${MV} ${DESTDIR}${PREFIX}/bin/${bins} ${DESTDIR}${PREFIX}/bin/${bins}-${PYVERSSUFFIX}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
