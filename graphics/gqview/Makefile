# $NetBSD: Makefile,v 1.15 2001/03/15 14:55:23 zuntum Exp $
#

DISTNAME=	gqview-0.10.1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	another gtk-based graphic file viewer

DEPENDS+=	gdk-pixbuf>=0.9.0:../../graphics/gdk-pixbuf
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
BUILD_DEPENDS+=	msgfmt:../../devel/gettext

USE_LIBINTL=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_GNOME_CONFIG=no
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}"
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CONFIGURE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

# for libpng recognition
EVAL_PREFIX+=	PNGDIR=png
CFLAGS+=	-I${PNGDIR}/include
CPPFLAGS+=	-I${PNGDIR}/include

.include "../../mk/bsd.pkg.mk"
