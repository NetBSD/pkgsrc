# $NetBSD: Makefile,v 1.1.1.1 2004/02/22 16:32:41 jmmv Exp $

DISTNAME=		gnome-media-2.4.1.1
PKGREVISION=		4
CATEGORIES=		multimedia gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-media/2.4/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of audio/multimedia applications for GNOME2

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PERL5=		build

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html
CONFIGURE_ENV+=		XGETTEXT="${LOCALBASE}/bin/xgettext"

.include "../../mk/bsd.prefs.mk"

post-extract:
	@cd ${WRKSRC}/gnome-cd && \
	${MV} freebsd-cdrom.h bsd-cdrom.h && \
	${MV} freebsd-cdrom.c bsd-cdrom.c

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "OpenBSD"
CONFIGURE_ENV+=		CDROM_HOST="bsd"
.endif

GCONF2_SCHEMAS=		CDDB-Slave2.schemas
GCONF2_SCHEMAS+=	gnome-cd.schemas
GCONF2_SCHEMAS+=	gnome-volume-control.schemas
GCONF2_SCHEMAS+=	gnome-sound-recorder.schemas

.include "../../audio/esound/buildlink3.mk"
.include "../../multimedia/gst-plugins/buildlink3.mk"
.include "../../multimedia/gstreamer/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gail/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
