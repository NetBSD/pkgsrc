# $NetBSD: Makefile,v 1.30 2005/06/02 21:48:42 wiz Exp $

DISTNAME=	xchat-1.8.11
PKGREVISION=	11
CATEGORIES=	chat x11
MASTER_SITES=	${HOMEPAGE}files/source/1.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://xchat.org/
COMMENT=	X11 (X Window System) IRC client, using the GTK+ toolkit

BUILD_USES_MSGFMT=	YES

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	YES
USE_X11BASE=		YES
USE_TOOLS+=		gmake grep perl
CONFIGURE_ARGS+=	--enable-python

CONFLICTS+=		xchat-gnome-[0-9]*

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		ac_cv_path_perlpath=${PERL5} pythonpath=${PYTHONBIN}
CONFIGURE_ARGS+=	--disable-gnome
CONFIGURE_ARGS+=	--disable-zvt

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xchat
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/xchat

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
