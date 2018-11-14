# $NetBSD: Makefile,v 1.92 2018/11/14 22:21:02 kleink Exp $

DISTNAME=		gmpc-11.8.16
PKGREVISION=		25
CATEGORIES=		audio
MASTER_SITES=		http://download.sarine.nl/Programs/gmpc/11.8/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=musicpd/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gmpc.wikia.com/wiki/Gnome_Music_Player_Client
COMMENT=		GNOME client for the Music Player Daemon
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake
PKGCONFIG_OVERRIDE=	data/gmpc.pc.in
REPLACE_SH=		remote/gmpc-remote-stream

.include "options.mk"

CONFIGURE_ARGS+=	--disable-libspiff

BUILDLINK_API_DEPENDS.libmpd+=	libmpd>=0.20.0
.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/gob2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
