# $NetBSD: Makefile,v 1.12 2026/02/15 18:22:30 gdt Exp $

DISTNAME=	iconv-1.0.13
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/iconv/
COMMENT=	Fast encoding conversion library for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	iconv

DEPENDS+=	erlang-p1_utils>=1.0.19:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
