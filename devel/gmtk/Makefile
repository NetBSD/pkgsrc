# $NetBSD: Makefile,v 1.1.1.1 2012/01/08 05:42:08 obache Exp $
#

DISTNAME=	gmtk-1.0.5
CATEGORIES=	devel
MASTER_SITES=	http://gmtk.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gmtk/
COMMENT=	Gnome-mplayer toolkit
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool msgfmt

PKGCONFIG_OVERRIDE+=	src/gmtk.pc.in
PKGCONFIG_OVERRIDE+=	src/gmlib.pc.in

.include "options.mk"

CONFIGURE_ARGS+=	--disable-gtk3
CONFIGURE_ARGS+=	--disable-gsettings
CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--disable-keystore

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
