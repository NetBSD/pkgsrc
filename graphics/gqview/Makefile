# $NetBSD: Makefile,v 1.10 2001/02/16 13:19:21 wiz Exp $
# FreeBSD Id: Makefile,v 1.7 1998/12/09 06:59:39 vanilla Exp
#

DISTNAME=	gqview-0.9.5
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gqview/}

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://gqview.sourceforge.net/index.html

DEPENDS+=	gdk-pixbuf>=0.9.0:../../graphics/gdk-pixbuf
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
BUILD_DEPENDS+=	msgfmt:../../devel/gettext

USE_LIBINTL=	yes
USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ac_cv_path_GNOME_CONFIG=no
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}"

# for libpng recognition
CFLAGS+=	"-I${LOCALBASE}/include"
CPPFLAGS+=	"-I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
