# $NetBSD: Makefile,v 1.8 1998/12/21 16:50:01 tron Exp $
#

DISTNAME=	imlib-1.8.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gnome.org/pub/imlib/TAR/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.labs.redhat.com/imlib/

DEPENDS+=	gtk+-1.1.9:../../x11/gtk
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	giflib-3.0:../../graphics/giflib

CONFLICTS=	imlib-*

USE_X11=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}
CONFIGURE_ENV+=		CPPFLAGS='-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib'

.include "../../mk/bsd.pkg.mk"
