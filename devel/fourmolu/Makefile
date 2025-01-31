# $NetBSD: Makefile,v 1.13 2025/01/31 03:55:34 pho Exp $

DISTNAME=	fourmolu-0.17.0.0
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Formatter for Haskell source code
LICENSE=	modified-bsd

# lib:fourmolu
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-memotrie/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-choice/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"

# exe:fourmolu
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../devel/hs-th-env/buildlink3.mk"
.include "../../devel/hs-terminal-size/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
