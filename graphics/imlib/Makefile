# $NetBSD: Makefile,v 1.34 2000/05/30 19:16:27 drochner Exp $
#

DISTNAME=	imlib-1.9.8.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/imlib/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.labs.redhat.com/imlib/

DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	libungif-*:../../graphics/libungif
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	netpbm-*:../../graphics/netpbm
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	tiff-*:../../graphics/tiff

USE_X11BASE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
PLIST_SUBST+=	LOCALBASE=${LOCALBASE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CPPFLAGS=	-DENABLE_NLS
.endif

CPPFLAGS+=	-I${LOCALBASE}/include

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imlib
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.gif *.html \
		${PREFIX}/share/doc/imlib
	${TEST} ${PREFIX} = ${LOCALBASE} || \
	${LN} -fs ${PREFIX}/share/aclocal/imlib.m4 \
		${LOCALBASE}/share/aclocal/imlib.m4

.include "../../mk/bsd.pkg.mk"
