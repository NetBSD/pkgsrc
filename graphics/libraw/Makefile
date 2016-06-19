# $NetBSD: Makefile,v 1.24 2016/06/19 05:04:57 markd Exp $

DISTNAME=	LibRaw-0.17.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	graphics
MASTER_SITES=	http://www.libraw.org/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libraw.org/
COMMENT=	Raw decoding/processing library
LICENSE=	gnu-lgpl-v2.1 OR cddl-1.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-demosaic-pack-gpl2
CONFIGURE_ARGS+=	--disable-demosaic-pack-gpl3

PKGCONFIG_OVERRIDE+=	libraw.pc.in
PKGCONFIG_OVERRIDE+=	libraw_r.pc.in

.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
