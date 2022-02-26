# $NetBSD: Makefile,v 1.2 2022/02/26 03:57:46 pho Exp $

DISTNAME=	floskell-0.10.6
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Flexible Haskell source code pretty printer
LICENSE=	modified-bsd

# lib:floskell
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../devel/hs-monad-dijkstra/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"

# exe:floskell
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
