# $NetBSD: Makefile,v 1.6 2020/03/23 18:09:59 nia Exp $

DISTNAME=	ezlib-1.0.7
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
