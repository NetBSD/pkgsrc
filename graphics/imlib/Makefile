# $NetBSD: Makefile,v 1.26 1999/10/09 20:12:10 jlam Exp $
#

DISTNAME=	imlib-1.9.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=gnome-1.0/sources/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.labs.redhat.com/imlib/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	libungif-*:../../graphics/libungif
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	netpbm-*:../../graphics/netpbm
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff

USE_X11BASE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib \
		-Wl,-R${X11BASE}/lib -L${X11BASE}/lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${PREFIX}/share/doc/imlib

.include "../../mk/bsd.pkg.mk"
