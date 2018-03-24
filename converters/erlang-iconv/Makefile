# $NetBSD: Makefile,v 1.8 2018/03/24 16:25:56 fhajny Exp $

DISTNAME=	iconv-1.0.7
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/iconv/
COMMENT=	Fast encoding conversion library for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	iconv

DEPENDS+=	erlang-p1_utils>=1.0.11:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
