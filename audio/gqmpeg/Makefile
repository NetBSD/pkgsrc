# $NetBSD: Makefile,v 1.34 2001/06/11 06:34:18 jlam Exp $
# FreeBSD Id: Makefile,v 1.6 1998/12/28 01:02:05 vanilla Exp

DISTNAME=		gqmpeg-0.8.3
PKGNAME=		${DISTNAME}nb1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gqmpeg/}

MAINTAINER=		rxg@ms25.url.com.tw
HOMEPAGE=		http://gqmpeg.sourceforge.net/
COMMENT=		GTK+ front end to mpg123

BUILD_USES_MSGFMT=	yes

DEPENDS+=		gdk-pixbuf>=0.8.0nb1:../../graphics/gdk-pixbuf
DEPENDS+=		gtk+-1.2.*:../../x11/gtk
DEPENDS+=		mpg123-0.59r:../../audio/mpg123

USE_LIBINTL=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--enable-japanese
CONFIGURE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

CPPFLAGS+=		-I${LOCALBASE}/include

# in case gnome isn't installed, we need to create the directories
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/gnome/apps/Multimedia
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps

.include "../../mk/bsd.pkg.mk"
