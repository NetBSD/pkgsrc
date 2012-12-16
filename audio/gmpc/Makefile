# $NetBSD: Makefile,v 1.55 2012/12/16 01:51:58 obache Exp $
#

DISTNAME=		gmpc-0.20.0
PKGREVISION=		16
CATEGORIES=		audio
MASTER_SITES=		http://download.sarine.nl/Programs/gmpc/0.20.0/ \
			${MASTER_SITE_SOURCEFORGE:=musicpd/}

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

CONFIGURE_ARGS+=	--enable-system-libsexy
CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}

BUILDLINK_API_DEPENDS.libmpd+=	libmpd>=0.20.0
.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/gob2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
