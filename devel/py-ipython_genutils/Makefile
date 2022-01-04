# $NetBSD: Makefile,v 1.8 2022/01/04 20:53:11 wiz Exp $

DISTNAME=	ipython_genutils-0.2.0
PKGREVISION=	3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/ipython_genutils/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ipython.org/
COMMENT=	Vestigial utilities from IPython
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

.if ${PYPKGPREFIX} == "py27"
_PYSETUPTOOLSINSTALLARGS:=	${PYSETUPTOOLSINSTALLARGS:N--single-version-externally-managed}
.endif

.include "../../mk/bsd.pkg.mk"
