# $NetBSD: Makefile,v 1.17 1998/06/10 08:02:08 agc Exp $

DISTNAME=	gimp-0.99.28
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v0.99/v0.99.28/  \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gimp/v0.99/v0.99.28/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gimp/v0.99/v0.99.28/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${GIMP_DATA}${EXTRACT_SUFX}

MAINTAINER=	bsieker@techfak.uni-bielefeld.de

BUILD_DEPENDS=	install-info:../../devel/gtexinfo
DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	mpeg-1.2.1:../../graphics/mpeg-lib
DEPENDS+=	png-0.96:../../graphics/png
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	gtk+-1.0.0:../../x11/gtk
DEPENDS+=	xpm-3.4j:../../graphics/xpm

GIMP_DATA=	gimp-data-extras-0.99a

.ifndef DISPLAY
IS_INTERACTIVE=	yes
.endif
USE_X11=	yes
USE_GTEXINFO=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
CFLAGS=		-pipe -O2 -I${LOCALBASE}/include -I${X11BASE}/include

MAN1=		gimp.1
INFO_FILES=	pdb.info

post-configure:
	@${ECHO_MSG} "--> now configuring in ${GIMP_DATA}"
	@(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${CONFIGURE_ENV} ${SH} \
		${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} )

PLIST_SRC=	${WRKDIR:T}/.PLIST-src

pre-build:
	@if [ "$$DISPLAY" = "" ]; then \
	  ${ECHO} "${DISTNAME} can only be built under X11."; \
	  exit 1; \
	 fi

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' ${LOCALBASE}/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SED} -e 's|\$${LOCALBASE}|'${LOCALBASE}'|g' < ${PKGDIR}/PLIST > ${PLIST_SRC}

post-install:
	@${ECHO_MSG} "--> now installing in ${GIMP_DATA}"
	@(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET})

.include <../../mk/bsd.pkg.mk>
