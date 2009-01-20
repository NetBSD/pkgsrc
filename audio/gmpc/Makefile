# $NetBSD: Makefile,v 1.28 2009/01/20 22:46:09 drochner Exp $
#

DISTNAME=		gmpc-0.17.0
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=musicpd/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sarine.nl/gmpc
COMMENT=		GNOME client for the Music Player Daemon

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config gmake
PKGCONFIG_OVERRIDE=	data/gmpc.pc.in

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=		xdg-1.1

.include "../../audio/libmpd/buildlink3.mk"
.include "../../devel/gob2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
