# $NetBSD: Makefile,v 1.25 1999/10/08 21:12:49 jlam Exp $
#

DISTNAME=	imlib-1.9.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.labs.redhat.com/imlib/

DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	netpbm-19940301:../../graphics/netpbm
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff

USE_X11BASE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ENV+=		CPPFLAGS='-I${LOCALBASE}/include -I${LOCALBASE}/include/giflib'

.include "../../mk/bsd.pkg.mk"

.if !defined(USE_LOCALBASE_FOR_X11)
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}
.endif
