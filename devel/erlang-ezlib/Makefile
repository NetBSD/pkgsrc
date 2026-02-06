# $NetBSD: Makefile,v 1.10 2026/02/06 21:52:33 gdt Exp $

DISTNAME=	ezlib-1.0.15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	ezlib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/ezlib
COMMENT=	Native zlib driver for Erlang / Elixir
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.26:../../misc/erlang-p1_utils

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
