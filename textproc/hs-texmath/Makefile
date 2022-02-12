# $NetBSD: Makefile,v 1.26 2022/02/12 08:50:55 pho Exp $

DISTNAME=	texmath-0.12.4
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Conversion between formats used to represent mathematics
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	-fexecutable

.include "../../converters/hs-aeson/buildlink3.mk" # Only used by the executable
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk" # Only used by the executable
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
