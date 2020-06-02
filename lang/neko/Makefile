# $NetBSD: Makefile,v 1.4 2020/06/02 08:24:12 adam Exp $

DISTNAME=	neko-2.3.0
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=HaxeFoundation/}
GITHUB_TAG=	v${PKGVERSION_NOREV:S/./-/g}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://nekovm.org/
COMMENT=	High-level dynamically typed programming language
LICENSE=	mit

TOOL_DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "options.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
