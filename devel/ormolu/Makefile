# $NetBSD: Makefile,v 1.9 2023/11/02 06:37:05 pho Exp $

DISTNAME=	ormolu-0.7.3.0
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Formatter for Haskell source code
LICENSE=	modified-bsd

# lib:ormolu
.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-Diff/buildlink3.mk"
.include "../../devel/hs-file-embed/buildlink3.mk"
.include "../../devel/hs-ghc-lib-parser/buildlink3.mk"
.include "../../textproc/hs-megaparsec/buildlink3.mk"
.include "../../devel/hs-memotrie/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"

# exe:ormolu
.include "../../devel/hs-optparse-applicative/application.mk"
.include "../../devel/hs-th-env/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
