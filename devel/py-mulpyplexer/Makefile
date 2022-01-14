#	$NetBSD: Makefile,v 1.3 2022/01/14 17:51:55 wiz Exp $

DISTNAME=	mulpyplexer-0.08
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mulpyplexer/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zardus/mulpyplexer/
COMMENT=	Python module to multiplex interactions with lists of objects
LICENSE=	2-clause-bsd

.include "../../lang/python/pyversion.mk"

.if ${PYPKGPREFIX} != "py27"
EGG_NAME=	mulpyplexer-0.8
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
