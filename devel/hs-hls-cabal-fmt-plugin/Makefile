# $NetBSD: Makefile,v 1.7 2023/11/08 13:18:45 wiz Exp $

DISTNAME=	hls-cabal-fmt-plugin-2.4.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Integration with the cabal-fmt code formatter
LICENSE=	apache-2.0

DEPENDS+=	cabal-fmt-[0-9]*:../../devel/cabal-fmt

.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp-types/buildlink3.mk"
.include "../../sysutils/hs-process-extras/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
