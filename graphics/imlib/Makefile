# $NetBSD: Makefile,v 1.28 1999/10/28 00:23:08 jlam Exp $
#

DISTNAME=	imlib-1.9.8
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/e/enlightenment/libs/ \
		${MASTER_SITE_GNOME:=sources/imlib/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.labs.redhat.com/imlib/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	libungif-*:../../graphics/libungif
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	netpbm-*:../../graphics/netpbm
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff

USE_X11BASE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS+=	-DENABLE_NLS
.endif

CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${PREFIX}/share/doc/imlib

.include "../../mk/bsd.pkg.mk"
