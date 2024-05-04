# $NetBSD: Makefile,v 1.14 2024/05/04 13:00:58 pho Exp $

DISTNAME=	hls-qualify-imported-names-plugin-2.4.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell Language Server plugin that qualifies imported names
LICENSE=	apache-2.0

# The upstream has already fixed it in git HEAD but hasn't released a new version.
BROKEN+=	"This package is currently incompatible with ghcide>=2.7, hls-plugin-api>=2.7"

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-graph/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
