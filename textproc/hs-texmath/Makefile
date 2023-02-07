# $NetBSD: Makefile,v 1.30 2023/02/07 01:41:14 pho Exp $

DISTNAME=	texmath-0.12.6
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Conversion between formats used to represent mathematics
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	-fexecutable

# lib:texmath
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"

# exe:texmath
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-pretty-show/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
