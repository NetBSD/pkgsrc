# $NetBSD: Makefile,v 1.13 2024/05/09 01:31:39 pho Exp $

DISTNAME=	aeson-pretty-0.8.10
PKGREVISION=	2
CATEGORIES=	converters

MAINTAINER=	pho@cielonegro.org
COMMENT=	JSON pretty-printing library and command-line tool
LICENSE=	modified-bsd

# lib:aeson-pretty
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"

# exe:aeson-pretty
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../textproc/hs-attoparsec-aeson/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
