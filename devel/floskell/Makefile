# $NetBSD: Makefile,v 1.11 2024/05/03 09:24:23 pho Exp $

DISTNAME=	floskell-0.11.1
PKGNAME=	${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Flexible Haskell source code pretty printer
LICENSE=	modified-bsd

# lib:floskell
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-attoparsec-aeson/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../devel/hs-monad-dijkstra/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"

# exe:floskell
.include "../../converters/hs-aeson-pretty/buildlink3.mk"
.include "../../textproc/hs-ansi-wl-pprint/buildlink3.mk"
.include "../../devel/hs-optparse-applicative/application.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
