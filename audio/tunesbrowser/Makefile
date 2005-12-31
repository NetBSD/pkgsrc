# $NetBSD: Makefile,v 1.9 2005/12/31 12:32:32 wiz Exp $
#

DISTNAME=		tunesbrowser-0.3.0
PKGREVISION=		1
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
DEPENDS+=		gst-plugins-esound>=0.8.1:../../audio/gst-plugins-esound
DEPENDS+=		gst-plugins-mad>=0.8.1:../../audio/gst-plugins-mad

BUILDLINK_DEPENDS.libopendaap+=	libopendaap>=0.4.0

.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../audio/libopendaap/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/gst-plugins-gnomevfs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
