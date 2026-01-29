# $NetBSD: Makefile,v 1.16 2026/01/29 13:42:17 pho Exp $

DISTNAME=	ormolu-0.7.7.0
PKGNAME=	${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Formatter for Haskell source code
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	Diff

# The GHC API has drastically changed between 9.10 and 9.14 and there's no
# easy fix. The upstream is working on an update to adopt the new
# API. Until it's done we can't build ormolu unfortunately:
# https://github.com/tweag/ormolu/pull/1175
BROKEN=		"ormolu is incompatible with ghc-lib-parser-9.14"

# lib:ormolu
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-memotrie/buildlink3.mk"
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-choice/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"

# exe:ormolu
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../devel/hs-th-env/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
