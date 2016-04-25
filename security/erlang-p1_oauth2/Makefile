# $NetBSD: Makefile,v 1.1 2016/04/25 14:30:45 fhajny Exp $

DISTNAME=	p1_oauth2-0.6.1
PKGNAME=	erlang-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/p1_oauth2/
COMMENT=	Erlang Oauth2 implementation
LICENSE=	mit

GITHUB_PROJECT=	oauth2

ERL_MOD_DIR=	lib/erlang/lib/${DISTNAME}

BUILD_TARGET=	compile

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
