# $NetBSD: Makefile,v 1.12 2011/05/29 17:55:58 gls Exp $
#

DISTNAME=		LibRaw-0.13.5
PKGNAME=		${DISTNAME:tl}
CATEGORIES=		graphics
MASTER_SITES=	http://www.libraw.org/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libraw.org/
COMMENT=	Raw decoding/processing library
LICENSE=	gnu-lgpl-v2.1 OR cddl-1.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=		pkg-config gmake
USE_LIBTOOL=	yes
MAKE_JOBS_SAFE=	no

CONFIGURE_ARGS+=	--disable-examples
CONFIGURE_ARGS+=	--disable-demosaic-pack-gpl2
CONFIGURE_ARGS+=	--disable-demosaic-pack-gpl3

PKGCONFIG_OVERRIDE+=	libraw.pc.in
PKGCONFIG_OVERRIDE+=	libraw_r.pc.in

.include "../../graphics/lcms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
