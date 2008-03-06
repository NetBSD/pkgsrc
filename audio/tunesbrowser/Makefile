# $NetBSD: Makefile,v 1.23 2008/03/06 14:53:48 wiz Exp $
#

DISTNAME=		tunesbrowser-0.3.0
PKGREVISION=		12
CATEGORIES=		audio
MASTER_SITES=		http://craz.net/programs/itunes/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://craz.net/programs/itunes/libopendaap.html
COMMENT=		Front-end for DAAP client

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/tunesbrowser
DEPENDS+=		gst-plugins0.8-esound>=0.8.1:../../audio/gst-plugins0.8-esound
DEPENDS+=		gst-plugins0.8-mad>=0.8.1:../../audio/gst-plugins0.8-mad

BUILDLINK_API_DEPENDS.libopendaap+=	libopendaap>=0.4.0

.include "../../multimedia/gst-plugins0.8/buildlink3.mk"
.include "../../audio/libopendaap/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../multimedia/gstreamer0.8/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../sysutils/gst-plugins0.8-gnomevfs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
