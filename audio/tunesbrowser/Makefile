# $NetBSD: Makefile,v 1.3 2005/03/20 11:09:47 jmmv Exp $
#

DISTNAME=		tunesbrowser-0.2.0
CATEGORIES=		audio
MASTER_SITES=		http://crazney.net/programs/itunes/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://crazney.net/programs/itunes/libopendaap.html
COMMENT=		Front-end for DAAP client

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILDLINK_DEPENDS.libopendaap+=	libopendaap>=0.3.0

.include "../../audio/gst-plugins-mad/buildlink3.mk"
# XXX Enable this dependency after the package is created (couldn't be done at
# XXX the moment because we were preparing the pkgsrc-2005Q1 branch).
#.include "../../audio/gst-plugins-spider/buildlink3.mk"
.include "../../audio/libopendaap/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../sysutils/gst-plugins-gnomevfs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
