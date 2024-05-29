# $NetBSD: Makefile,v 1.71 2024/05/29 16:32:02 adam Exp $

DISTNAME=	gmtk-1.0.9
PKGREVISION=	44
CATEGORIES=	devel
MASTER_SITES=	http://gmtk.googlecode.com/svn/packages/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/archive/p/gmtk/
COMMENT=	Gnome-mplayer toolkit
LICENSE=	gnu-gpl-v2

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
