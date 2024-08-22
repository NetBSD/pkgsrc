# $NetBSD: Makefile,v 1.7 2024/08/22 06:09:13 adam Exp $

DISTNAME=	p1_oauth2-0.6.14
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	oauth2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/p1_oauth2
COMMENT=	Erlang Oauth2 implementation
LICENSE=	mit

ERL_MOD_DIR=	lib/erlang/lib/${DISTNAME}

BUILD_TARGET=	compile

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
