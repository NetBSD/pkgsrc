# $NetBSD: Makefile,v 1.26 2014/02/12 23:18:03 tron Exp $
#

DISTNAME=	pfstools-1.7.0
PKGREVISION=	24
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfstools/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pfstools.sourceforge.net/
COMMENT=	Tools for manipulating HDR images and video frames

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--enable-ppm
CONFIGURE_ARGS+=	--enable-tiff
CONFIGURE_ARGS+=	--disable-jpeghdr
CONFIGURE_ARGS+=	--disable-matlab
# patch-aa
CONFIGURE_ENV+=		NETPBM_CFLAGS=-I${BUILDLINK_PREFIX.netpbm}/include

PKGCONFIG_OVERRIDE+=	src/pfs/pfs.pc.in

DEPENDS+=	dcraw-[0-9]*:../../graphics/dcraw

.include "options.mk"

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
