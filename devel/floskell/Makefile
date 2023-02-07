# $NetBSD: Makefile,v 1.7 2023/02/07 01:40:25 pho Exp $

DISTNAME=	floskell-0.10.7
PKGNAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Flexible Haskell source code pretty printer
LICENSE=	modified-bsd

# floskell is built with optparse-applicative, and can generate shell
# completion scripts automatically.
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:floskell
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../devel/hs-monad-dijkstra/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"

# exe:floskell
.include "../../converters/hs-aeson-pretty/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
