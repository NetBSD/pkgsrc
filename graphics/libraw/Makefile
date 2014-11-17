# $NetBSD: Makefile,v 1.22 2014/11/17 19:04:25 joerg Exp $

DISTNAME=	LibRaw-0.15.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
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
#MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-demosaic-pack-gpl2
CONFIGURE_ARGS+=	--disable-demosaic-pack-gpl3

PKGCONFIG_OVERRIDE+=	libraw.pc.in
PKGCONFIG_OVERRIDE+=	libraw_r.pc.in

.include "../../graphics/lcms2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
