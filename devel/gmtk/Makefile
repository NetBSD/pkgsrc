# $NetBSD: Makefile,v 1.8.2.1 2012/10/03 12:07:09 spz Exp $
#

DISTNAME=	gmtk-1.0.6
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://gmtk.googlecode.com/files/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://code.google.com/p/gmtk/
COMMENT=	Gnome-mplayer toolkit
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config intltool msgfmt

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
