# $NetBSD: Makefile,v 1.12 1999/01/16 02:38:43 tron Exp $
#

DISTNAME=	imlib-1.9.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gnome.org/pub/imlib/TAR/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/imlib/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PNG_DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.labs.redhat.com/imlib/

DEPENDS+=	gtk+-1.1.12:../../x11/gtk
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	giflib-3.0:../../graphics/giflib

CONFLICTS=	imlib-*

USE_X11=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

LDFLAGS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-gtk-prefix=${X11BASE}
CONFIGURE_ENV+=		CPPFLAGS='-I${PNG_WRKSRC} -I${LOCALBASE}/include -I${LOCALBASE}/include/giflib'

PNG_DISTNAME=		libpng-1.0.1
PNG_MAKE_PROGRAM=	make
PNG_MAKEFILE=		scripts/makefile.std
PNG_WRKSRC=		${WRKDIR}/${PNG_DISTNAME}

pre-build:
	@cd ${PNG_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PNG_MAKE_PROGRAM} ${MAKE_FLAGS} \
	  -f ${PNG_MAKEFILE}  ${ALL_TARGET}

pre-install:	
	@cd ${PNG_WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${PNG_MAKE_PROGRAM} ${MAKE_FLAGS} \
	  -f ${PNG_MAKEFILE}  ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
