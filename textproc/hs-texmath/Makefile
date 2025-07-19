# $NetBSD: Makefile,v 1.41 2025/07/19 20:47:04 wiz Exp $

DISTNAME=	texmath-0.12.10.3
CATEGORIES=	textproc

MAINTAINER=	szptvlfn@NetBSD.org
COMMENT=	Conversion between formats used to represent mathematics
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	-fexecutable

.include "options.mk"

# lib:texmath
.include "../../textproc/hs-pandoc-types/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../textproc/hs-typst-symbols/buildlink3.mk"
.include "../../textproc/hs-xml/buildlink3.mk"

# exe:texmath
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.include "../../devel/hs-pretty-show/buildlink3.mk"

.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
