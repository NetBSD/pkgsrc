# $NetBSD: Makefile,v 1.2 2013/04/30 21:49:25 cheusov Exp $
#

DISTNAME=	vdpau-driver-${PKGNAME:C/^.*-//}
PKGNAME=	libva-driver-vdpau-0.7.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_BACKUP}
		#http://cgit.freedesktop.org/vaapi/vdpau-driver/snapshot/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://cgit.freedesktop.org/vaapi/vdpau-driver
COMMENT=	VDPAU-based backend for VAAPI
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoconf autoreconf pkg-config gmake
USE_LIBTOOL=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../multimedia/libvdpau/buildlink3.mk"
.include "../../multimedia/libva/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
