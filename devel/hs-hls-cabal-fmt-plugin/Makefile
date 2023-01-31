# $NetBSD: Makefile,v 1.1 2023/01/31 17:16:55 pho Exp $

DISTNAME=	hls-cabal-fmt-plugin-0.1.0.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Integration with the cabal-fmt code formatter
LICENSE=	apache-2.0

DEPENDS+=	cabal-fmt-[0-9]*:../../devel/cabal-fmt

.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
