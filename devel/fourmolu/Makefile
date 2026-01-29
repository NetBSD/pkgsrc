# $NetBSD: Makefile,v 1.17 2026/01/29 13:45:24 pho Exp $

DISTNAME=	fourmolu-0.17.0.0
PKGNAME=	${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Formatter for Haskell source code
LICENSE=	modified-bsd

# The GHC API has drastically changed between 9.10 and 9.14 and there's no
# easy fix. The upstream is working on an update to adopt the new
# API. Until it's done we can't build fourmolu unfortunately:
# https://github.com/fourmolu/fourmolu/pull/454
BROKEN=		"fourmolu is incompatible with ghc-lib-parser-9.14"

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
