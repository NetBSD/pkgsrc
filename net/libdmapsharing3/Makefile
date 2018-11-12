# $NetBSD: Makefile,v 1.41 2018/11/12 03:52:43 ryoon Exp $

DISTNAME=	libdmapsharing-2.9.15
PKGNAME=	${DISTNAME:S/sharing/sharing3/}
PKGREVISION=	38
CATEGORIES=	net
MASTER_SITES=	https://www.flyn.org/projects/libdmapsharing/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Implementation of the DMAP family of protocols (v3)
HOMEPAGE=	https://www.flyn.org/projects/libdmapsharing/
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE=	libdmapsharing-3.0.pc.in

BUILDLINK_ABI_DEPENDS.gst-plugins0.10-base+= gst-plugins0.10-base>=0.10.23.2
BUILDLINK_ABI_DEPENDS.libsoup+= libsoup>=2.32

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgee0.6/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
