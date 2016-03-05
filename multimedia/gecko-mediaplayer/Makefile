# $NetBSD: Makefile,v 1.41 2016/03/05 11:28:59 jperkin Exp $
#

DISTNAME=	gecko-mediaplayer-1.0.9
PKGREVISION=	3
CATEGORIES=	multimedia www
MASTER_SITES=	http://gecko-mediaplayer.googlecode.com/svn/packages/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gecko-mediaplayer/
COMMENT=	Multimedia browser plugin for Gecko based browsers
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnome-mplayer>=${PKGVERSION_NOREV}:../../multimedia/gnome-mplayer

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config msgfmt

GCONF_SCHEMAS+=		gecko-mediaplayer.schemas

CONFIGURE_ARGS+=	--with-plugin-dir=${PREFIX}/lib/netscape/plugins
CONFIGURE_ARGS+=	--with-libcurl

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gmtk/buildlink3.mk"
.include "../../devel/npapi-sdk/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=	dbus>=0.95
.include "../../sysutils/dbus/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.70
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../mk/dlopen.buildlink3.mk"
.if empty(BUILDLINK_LDADD.ldl)
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif
.include "../../mk/bsd.pkg.mk"
