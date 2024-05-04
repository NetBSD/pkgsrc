# $NetBSD: Makefile,v 1.8 2024/05/04 12:51:19 pho Exp $

DISTNAME=	hls-hlint-plugin-2.4.0.0
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hlint integration plugin with Haskell Language Server
LICENSE=	apache-2.0

# The upstream has already fixed it in git HEAD but hasn't released a new version.
BROKEN+=	"This package is currently broken because it's incompatible with GHC 9.8"

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-apply-refact/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../misc/hs-extra/buildlink3.mk"
.include "../../devel/hs-ghc-exactprint/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser-ex/buildlink3.mk"
.include "../../devel/hs-ghcide/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hlint/buildlink3.mk"
.include "../../devel/hs-hls-plugin-api/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../devel/hs-lsp/buildlink3.mk"
.include "../../devel/hs-refact/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../sysutils/hs-temporary/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
