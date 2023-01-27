# $NetBSD: Makefile,v 1.8 2023/01/27 16:06:25 pho Exp $

DISTNAME=	aeson-pretty-0.8.9
PKGREVISION=	3
CATEGORIES=	converters

MAINTAINER=	pho@cielonegro.org
COMMENT=	JSON pretty-printing library and command-line tool
LICENSE=	modified-bsd

HASKELL_UNRESTRICT_DEPENDENCIES+=	\
	aeson

# lib:aeson-pretty
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../devel/hs-base-compat/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"

# exe:aeson-pretty
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-cmdargs/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
