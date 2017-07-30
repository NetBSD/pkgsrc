# $NetBSD: Makefile,v 1.3 2017/07/30 22:32:14 wiz Exp $

DISTNAME=	ezlib-1.0.2
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
