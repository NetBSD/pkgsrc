# $NetBSD: Makefile,v 1.17 2010/06/13 22:44:25 wiz Exp $

DISTNAME=	gpsdrive-1.31
PKGREVISION=	14
CATEGORIES=	geography
MASTER_SITES=	http://gpsdrive.kraftvoll.at/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://gpsdrive.kraftvoll.at/
COMMENT=	GPS Navigation system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	gpsd>=1.07:../../geography/gpsd
DEPENDS+=	wget>=1:../../net/wget

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash:run perl:run

# XXX make this an option
CONFIGURE_ARGS+=	--disable-mysql

REPLACE_BASH=		src/gpsfetchmap
REPLACE_PERL=		src/gpspoint2gpsdrive.pl src/wpcvt

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
