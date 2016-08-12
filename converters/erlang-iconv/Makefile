# $NetBSD: Makefile,v 1.2 2016/08/12 09:47:06 fhajny Exp $

DISTNAME=	iconv-1.0.2
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/iconv/
COMMENT=	Fast encoding conversion library for Erlang / Elixir
LICENSE=	apache-2.0

GITHUB_PROJECT=	iconv

DEPENDS+=	erlang-p1_utils>=1.0.5:../../misc/erlang-p1_utils

GNU_CONFIGURE=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
