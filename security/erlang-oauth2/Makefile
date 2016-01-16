# $NetBSD: Makefile,v 1.2 2016/01/16 16:42:24 fhajny Exp $

DISTNAME=	oauth2-0.6.0
PKGNAME=	erlang-${DISTNAME}.20150911
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=kivra/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/kivra/oauth2/
COMMENT=	Erlang Oauth2 implementation
LICENSE=	mit

GITHUB_PROJECT=	oauth2
GITHUB_TAG=	8d129fbf8866930b4ffa6dd84e65bd2b32b9acb8
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

BUILD_TARGET=	compile

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
