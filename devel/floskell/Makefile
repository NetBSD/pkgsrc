# $NetBSD: Makefile,v 1.3 2022/02/26 08:37:07 pho Exp $

DISTNAME=	floskell-0.10.6
PKGNAME=	${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Flexible Haskell source code pretty printer
LICENSE=	modified-bsd

# purs is built with optparse-applicative, and can generate shell
# completion scripts automatically.
.include "../../devel/hs-optparse-applicative/application.mk"

# lib:floskell
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../devel/hs-haskell-src-exts/buildlink3.mk"
.include "../../devel/hs-monad-dijkstra/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"

# exe:floskell
.include "../../converters/hs-aeson-pretty/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
