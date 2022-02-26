# $NetBSD: Makefile,v 1.2 2022/02/26 03:57:59 pho Exp $

DISTNAME=	hls-refine-imports-plugin-1.0.1.0
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Refine imports plugin for Haskell Language Server
LICENSE=	apache-2.0

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-explicit-imports-plugin/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
