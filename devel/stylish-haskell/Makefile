# $NetBSD: Makefile,v 1.4 2025/02/02 13:05:32 pho Exp $

DISTNAME=	stylish-haskell-0.14.6.0
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Haskell code prettifier
LICENSE=	modified-bsd

BROKEN+=	"stylish-haskell is not compatible with GHC 9.10: https://github.com/haskell/stylish-haskell/issues/479"

# lib:stylish-haskell
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser-ex/buildlink3.mk"
.include "../../textproc/hs-HsYAML/buildlink3.mk"
.include "../../textproc/hs-HsYAML-aeson/buildlink3.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"

# exe:stylish-haskell
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser-ex/buildlink3.mk"
.include "../../textproc/hs-HsYAML/buildlink3.mk"
.include "../../textproc/hs-HsYAML-aeson/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../textproc/hs-regex-tdfa/buildlink3.mk"
.include "../../devel/hs-strict/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
