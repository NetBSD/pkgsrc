# $NetBSD: Makefile,v 1.23 1998/08/20 15:17:00 tsarna Exp $

DISTNAME=	gimp-1.0.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v1.0/v1.0.0/ \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gimp/v1.0/v1.0.0/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${GIMP_DATA}${EXTRACT_SUFX}

MAINTAINER=	bsieker@techfak.uni-bielefeld.de
HOMEPAGE=	http://www.gimp.org/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	gtk+-1.0.4:../../x11/gtk
DEPENDS+=	mpeg-1.2.1:../../graphics/mpeg-lib
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS+=	gimp-0.99.28

GIMP_DATA=	gimp-data-extras-1.0.0

.ifndef DISPLAY
IS_INTERACTIVE=	yes
.endif
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"
CFLAGS=		-pipe -O2 -I${LOCALBASE}/include

INFO_FILES=	pdb.info

post-configure:
	@${ECHO_MSG} "--> now configuring in ${GIMP_DATA}"
	@(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${CONFIGURE_ENV} ${SH} \
		${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} )

pre-build:
	@if [ "$$DISPLAY" = "" ]; then \
	  ${ECHO} "${DISTNAME} can only be built under X11."; \
	  exit 1; \
	 fi

post-install:
	@${ECHO_MSG} "--> now installing in ${GIMP_DATA}"
	@(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include <../../mk/bsd.pkg.mk>
