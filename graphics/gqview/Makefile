# $NetBSD: Makefile,v 1.18 2001/06/11 06:34:36 jlam Exp $
#

DISTNAME=	gqview-0.10.1
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/
COMMENT=	another gtk-based graphic file viewer

BUILD_USES_MSGFMT=	yes
DEPENDS+=	gdk-pixbuf>=0.9.0:../../graphics/gdk-pixbuf
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_LIBINTL=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_GNOME_CONFIG=no
CONFIGURE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

# for libpng recognition
EVAL_PREFIX+=	PNGDIR=png
CFLAGS+=	-I${PNGDIR}/include
CPPFLAGS+=	-I${PNGDIR}/include

.include "../../mk/bsd.pkg.mk"
