# $NetBSD: Makefile,v 1.11 2018/03/24 14:25:28 fhajny Exp $

DISTNAME=	cache_tab-1.0.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/cache_tab/
COMMENT=	In-memory cache Erlang libraries
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.11:../../misc/erlang-p1_utils

GITHUB_PROJECT=	cache_tab

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
