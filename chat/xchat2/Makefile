# $NetBSD: Makefile,v 1.43 2005/06/02 22:08:29 tron Exp $

DISTNAME=		xchat-2.4.1
PKGREVISION=		1
CATEGORIES=		chat gnome
MASTER_SITES=		http://www.xchat.org/files/source/2.4/
EXTRACT_SUFX=		.tar.bz2

PATCH_SITES=		${MASTER_SITES:=patches/}
PATCHFILES=		xc241-fix-fetext.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://www.xchat.org/
COMMENT=		X11 (X Window System) IRC client, using the GTK2 toolkit

BUILD_USES_MSGFMT=	YES

CONFLICTS=		xchat-gnome-[0-9]*

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

USE_DIRS+=		xdg-1.1
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--enable-textfe
CONFIGURE_ARGS+=	--enable-tcl=no
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python

LDFLAGS.IRIX+=		-lX11
LDFLAGS.Darwin+=	-lX11

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xchat/plugins

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
