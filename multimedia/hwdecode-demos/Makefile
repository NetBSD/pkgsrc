# $NetBSD: Makefile,v 1.16 2018/11/14 22:22:06 kleink Exp $
#

DISTNAME=	hwdecode-demos-0.9.4
PKGREVISION=	11
CATEGORIES=	multimedia
#MASTER_SITES=	http://www.splitted-desktop.com/~gbeauchesne/hwdecode-demos/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.splitted-desktop.com/~gbeauchesne/
COMMENT=	Standalone programs showing off various HW acceleration APIs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

PLIST_VARS+=	vdpau vaapi

.include "../../multimedia/libvdpau/buildlink3.mk"
.if ${VDPAU_AVAILABLE} == yes
PLIST.vdpau=	yes
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif
.include "../../multimedia/libva/buildlink3.mk"
.if ${VAAPI_AVAILABLE} == yes
PLIST.vaapi=	yes
.else
CONFIGURE_ARGS+=	--disable-vaapi
.endif

.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
