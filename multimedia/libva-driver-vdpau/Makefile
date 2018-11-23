# $NetBSD: Makefile,v 1.7 2018/11/23 08:06:32 ryoon Exp $
#

DISTNAME=	vdpau-driver-${PKGNAME:C/^.*-//}
PKGNAME=	libva-driver-vdpau-0.7.4
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_BACKUP}
		#https://cgit.freedesktop.org/vaapi/vdpau-driver/snapshot/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://cgit.freedesktop.org/vaapi/vdpau-driver
COMMENT=	VDPAU-based backend for VAAPI
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoconf autoreconf pkg-config gmake
USE_LIBTOOL=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../multimedia/libvdpau/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"

.if ${VAAPI_AVAILABLE} != "yes"
PKG_SKIP_REASON+=	"No VAAPI support on this platform"
.endif

.include "../../mk/bsd.pkg.mk"
