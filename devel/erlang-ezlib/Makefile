# $NetBSD: Makefile,v 1.2 2017/01/21 20:10:55 fhajny Exp $

DISTNAME=	ezlib-1.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/ezlib/
COMMENT=	Native zlib driver for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	ezlib

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
