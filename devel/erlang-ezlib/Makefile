# $NetBSD: Makefile,v 1.7 2021/01/15 23:40:00 triaxx Exp $

DISTNAME=	ezlib-1.0.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	ezlib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/ezlib
COMMENT=	Native zlib driver for Erlang / Elixir
LICENSE=	apache-2.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
