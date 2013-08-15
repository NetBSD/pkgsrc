# $NetBSD: Makefile,v 1.36 2013/08/15 07:20:27 obache Exp $
#

DISTNAME=	ario-1.5.1
PKGREVISION=	20
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ario-player/1.5.1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ario-player.sourceforge.net/
COMMENT=	Client for mpd
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	intltool msgfmt pkg-config gmake
USE_LIBTOOL=	yes
CONFIGURE_ARGS+= --disable-avahi
CONFIGURE_ARGS+= --with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}

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
.include "../../sysutils/libnotify07/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
#.include "../../net/avahi/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
BUILDLINK_API_DEPENDS.libgcrypt+=	libgcrypt>=1.4.0
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
