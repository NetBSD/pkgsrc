# $NetBSD: Makefile,v 1.1 2016/07/24 19:11:27 agc Exp $

DISTNAME=	byterun
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}-20160218
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=nedbat/}
GITHUB_PROJECT=	byterun
GITHUB_TAG=	de8519308a90bed6881196066dd9158ec3e4ba2b

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nedbat/byterun
COMMENT=	Python implementation of a python interpreter
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}-${GITHUB_TAG}

DEPENDS+=       ${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/distutils.mk"

.include "../../mk/bsd.pkg.mk"
