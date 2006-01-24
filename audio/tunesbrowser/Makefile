# $NetBSD: Makefile,v 1.11 2006/01/24 07:31:55 wiz Exp $
#

DISTNAME=		tunesbrowser-0.3.0
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://craz.net/programs/itunes/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://craz.net/programs/itunes/libopendaap.html
COMMENT=		Front-end for DAAP client

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/tunesbrowser
DEPENDS+=		gst-plugins0.8-esound>=0.8.1:../../audio/gst-plugins0.8-esound
DEPENDS+=		gst-plugins0.8-mad>=0.8.1:../../audio/gst-plugins0.8-mad

BUILDLINK_DEPENDS.libopendaap+=	libopendaap>=0.4.0

.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../audio/libopendaap/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/gst-plugins0.8-gnomevfs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
