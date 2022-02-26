# $NetBSD: Makefile,v 1.2 2022/02/26 03:57:46 pho Exp $

DISTNAME=	fourmolu-0.5.0.1
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Formatter for Haskell source code
LICENSE=	modified-bsd

# lib:fourmolu
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-HsYAML/buildlink3.mk"
.include "../../textproc/hs-HsYAML-aeson/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"

# exe:fourmolu
.include "../../devel/hs-gitrev/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
