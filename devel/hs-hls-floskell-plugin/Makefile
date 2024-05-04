# $NetBSD: Makefile,v 1.14 2024/05/04 12:54:53 pho Exp $

DISTNAME=	hls-floskell-plugin-2.4.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Integration with the Floskell code formatter
LICENSE=	apache-2.0

# The upstream has already fixed it in git HEAD but hasn't released a new version.
BROKEN+=	"This package is currently incompatible with GHC >= 9.7"

.include "../../devel/floskell/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
