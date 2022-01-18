# $NetBSD: Makefile,v 1.24 2022/01/18 02:48:28 pho Exp $

DISTNAME=	texmath-0.12.2
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Conversion between formats used to represent mathematics
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	-fexecutable

.include "../../converters/hs-aeson/buildlink3.mk" # Only used by the executable
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk" # Only used by the executable
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
