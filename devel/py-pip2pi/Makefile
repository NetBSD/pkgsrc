# $NetBSD: Makefile,v 1.1 2023/02/27 18:54:51 nikita Exp $

DISTNAME=	pip2pi-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip2pi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wolever/pip2pi/
COMMENT=	Build a PyPI-compatible package repository from pip
LICENSE=	2-clause-bsd

PYTHON_VERSIONED_DEPENDENCIES+=	pip

post-install:
.for bins in dir2pi pip2pi pip2tgz
	${MV} ${DESTDIR}${PREFIX}/bin/${bins} ${DESTDIR}${PREFIX}/bin/${bins}-${PYVERSSUFFIX}
.endfor

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
