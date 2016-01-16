# $NetBSD: Makefile,v 1.4 2016/01/16 19:01:20 fhajny Exp $

DISTNAME=	cache_tab-1.0.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/processone/cache_tab/
COMMENT=	In-memory cache Erlang libraries
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils-[0-9]*:../../misc/erlang-p1_utils

GITHUB_PROJECT=	cache_tab

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
