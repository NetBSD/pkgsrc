# $NetBSD: Makefile,v 1.4 2009/08/26 19:56:57 sno Exp $
#

DISTNAME=	tomoe-gtk-0.6.0
PKGREVISION=	2
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tomoe/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tomoe.sourceforge.jp/
COMMENT=	GUI library for tomoe's GTK+ GUI parts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config msgfmt
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	tomoe-gtk.pc.in

CONFIGURE_ARGS+=	--without-python
# enable again once upstream supports gucharmap-2, or a
# gucharmap-1 package was created
CONFIGURE_ARGS+=	--without-gucharmap

.include "../../inputmethod/tomoe/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
