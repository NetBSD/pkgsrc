# $NetBSD: Makefile,v 1.30 2001/03/01 17:12:28 jlam Exp $
# FreeBSD Id: Makefile,v 1.6 1998/12/28 01:02:05 vanilla Exp
#

DISTNAME=		gqmpeg-0.8.3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gqmpeg/}

MAINTAINER=		rxg@ms25.url.com.tw
HOMEPAGE=		http://gqmpeg.sourceforge.net/
COMMENT=		GTK+ front end to mpg123

DEPENDS+=		gdk-pixbuf>=0.8.0nb1:../../graphics/gdk-pixbuf
BUILD_DEPENDS+=		msgfmt:../../devel/gettext
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		mpg123-0.59r:../../audio/mpg123

USE_LIBINTL=		# defined
USE_X11BASE=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--enable-japanese
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

# in case gnome isn't installed, we need to create the directories
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gnome/apps/Multimedia
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
