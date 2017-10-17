# $NetBSD: Makefile,v 1.2 2017/10/17 18:06:44 adam Exp $

DISTNAME=	entrypoints-0.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/entrypoints/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/takluyver/entrypoints
COMMENT=	Discover and load entry points from installed packages
LICENSE=	mit

.include "../../lang/python/distutils.mk"

.if ${PYPKGPREFIX} == py27
DEPENDS+=	${PYPKGPREFIX}-configparser>=3.5:../../devel/py-configparser
.endif

USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
