# $NetBSD: Makefile,v 1.3 2024/05/09 01:32:39 pho Exp $

DISTNAME=	attoparsec-aeson-2.2.0.1
PKGREVISION=	2
CATEGORIES=	textproc converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Parsing of aeson's Value with attoparsec
LICENSE=	modified-bsd

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../math/hs-integer-conversion/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
