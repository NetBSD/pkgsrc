# $NetBSD: Makefile,v 1.3 1999/11/30 01:31:59 hubertf Exp $

DISTNAME=	gphoto-0.4.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gphoto.org/projects/gphoto/pub/tar/0.4/

MAINTAINER=	jmcm@cs.cmu.edu
HOMEPAGE=	http://www.gphoto.org/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	gtk+-1.2.6:../../x11/gtk
DEPENDS+=	glib-1.2.6:../../devel/glib
DEPENDS+=	imlib-1.9.8:../../graphics/imlib

USE_X11BASE=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.pkg.mk"
