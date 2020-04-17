# $NetBSD: Makefile,v 1.2 2020/04/17 00:32:04 js Exp $

DISTNAME=	pymacaroons-0.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymacaroons/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Python implementation of Macaroons
LICENSE=	mit

USE_LANGUAGES=	# empty

.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
