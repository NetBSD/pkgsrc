# $NetBSD: Makefile,v 1.2 2016/01/16 18:50:40 fhajny Exp $

DISTNAME=	eredis-1.0.8
PKGNAME=	erlang-${DISTNAME}.20150910
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=wooga/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/wooga/eredis/
COMMENT=	Erlang Redis client
LICENSE=	mit

GITHUB_PROJECT=	eredis
GITHUB_TAG=	bf12ecb30253c84a2331f4f0d93fd68856fcb9f4
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
