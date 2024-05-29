# $NetBSD: Makefile,v 1.40 2024/05/29 16:31:29 adam Exp $

DISTNAME=	farstream-0.2.9
PKGREVISION=	20
CATEGORIES=	chat multimedia
MASTER_SITES=	https://freedesktop.org/software/farstream/releases/farstream/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/Farstream/
COMMENT=	Audio/video communications framework
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf automake autoreconf

PKGCONFIG_OVERRIDE+=	farstream.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=1.4
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../net/gupnp-igd/buildlink3.mk"
BUILDLINK_API_DEPENDS.libnice+=	libnice>=0.1.0
.include "../../net/libnice/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
