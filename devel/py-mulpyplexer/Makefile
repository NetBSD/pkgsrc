# $NetBSD: Makefile,v 1.4 2023/02/27 13:56:17 adam Exp $

DISTNAME=	mulpyplexer-0.09
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mulpyplexer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zardus/mulpyplexer
COMMENT=	Python module to multiplex interactions with lists of objects
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} != "py27"
EGG_NAME=	mulpyplexer-0.9
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
