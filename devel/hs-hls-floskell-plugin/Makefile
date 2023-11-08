# $NetBSD: Makefile,v 1.13 2023/11/08 13:18:46 wiz Exp $

DISTNAME=	hls-floskell-plugin-2.4.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Integration with the Floskell code formatter
LICENSE=	apache-2.0

BROKEN+=	"This package is currently incompatible with GHC >= 9.5"

.include "../../devel/floskell/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
