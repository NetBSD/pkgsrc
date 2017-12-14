# $NetBSD: Makefile,v 1.4 2017/12/14 20:46:45 fhajny Exp $

DISTNAME=	ezlib-1.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/ezlib/
COMMENT=	Native zlib driver for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	ezlib

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
