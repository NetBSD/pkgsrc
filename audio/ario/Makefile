# $NetBSD: Makefile,v 1.14 2012/01/24 09:10:54 sbd Exp $
#

DISTNAME=	ario-1.5.1
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ario-player/1.5.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ario-player.sourceforge.net/
COMMENT=	mpd client
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool msgfmt pkg-config gmake
USE_LIBTOOL=	yes
CONFIGURE_ARGS+= --disable-avahi
PKG_DESTDIR_SUPPORT= user-destdir

.for fl in clobbered empty-body ignored-qualifiers \
	missing-parameter-type old-style-declaration \
	override-init type-limits
BUILDLINK_TRANSFORM+=	rm:-W${fl}
.endfor

.include "../../audio/libmpdclient/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
#.include "../../net/avahi/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
