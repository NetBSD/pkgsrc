# $NetBSD: Makefile,v 1.14 2024/05/04 13:03:44 pho Exp $

DISTNAME=	hls-pragmas-plugin-2.4.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pragmas plugin for Haskell Language Server
LICENSE=	apache-2.0

# The upstream has already fixed it in git HEAD but hasn't released a new version.
BROKEN+=	"This package is currently incompatible with ghcide>=2.7, hls-plugin-api>=2.7"

.include "../../misc/hs-extra/buildlink3.mk"
.include "../../textproc/hs-fuzzy/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
