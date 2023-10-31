# $NetBSD: Makefile,v 1.11 2023/10/31 14:47:37 pho Exp $

DISTNAME=	hls-refine-imports-plugin-2.0.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Refine imports plugin for Haskell Language Server
LICENSE=	apache-2.0

BROKEN+=	"This package is currently broken because it's incompatible with hls-plugin-api-2.4"

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-explicit-imports-plugin/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
