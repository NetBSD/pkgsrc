# $NetBSD: Makefile,v 1.17 2026/02/15 18:22:31 gdt Exp $

DISTNAME=	cache_tab-1.0.33
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=processone/}
GITHUB_PROJECT=	cache_tab

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/processone/cache_tab
COMMENT=	In-memory cache Erlang libraries
LICENSE=	apache-2.0

DEPENDS+=	erlang-p1_utils>=1.0.25:../../misc/erlang-p1_utils

.include "../../lang/erlang/module.mk"
.include "../../mk/bsd.pkg.mk"
