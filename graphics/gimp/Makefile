# $NetBSD: Makefile,v 1.12 1998/05/03 11:00:36 frueauf Exp $

DISTNAME=	gimp-0.99.26
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v0.99/v0.99.26/  \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gimp/v0.99/v0.99.26/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gimp/v0.99/v0.99.26/
GIMP_DATA=	gimp-data-extras-0.99a
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${GIMP_DATA}${EXTRACT_SUFX}

MAINTAINER=	bsieker@techfak.uni-bielefeld.de

DEPENDS+=	xpm-3.4j:../../graphics/xpm
DEPENDS+=	tiff-3.4:../../graphics/tiff
DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	png-0.96:../../graphics/png
DEPENDS+=	mpeg-1.2.1:../../graphics/mpeg-lib
DEPENDS+=	gtk+-1.0.0:../../x11/gtk

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

CFLAGS=		-pipe -O2 -I${LOCALBASE}/include -I${X11BASE}/include
USE_GTEXINFO=	yes

MAN1=		gimp.1

INFO_FILES=	pdb.info

post-configure:
	@${ECHO_MSG} "--> now configuring in ${GIMP_DATA}"
	@(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${CONFIGURE_ENV} ${SH} \
		${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} )

PLIST_SRC=	${WRKDIR:T}/.PLIST-src

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' ${LOCALBASE}/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SED} -e 's|\$${LOCALBASE}|'${LOCALBASE}'|g' < ${PKGDIR}/PLIST > ${PLIST_SRC}

post-install:
	@${ECHO_MSG} "--> now installing in ${GIMP_DATA}"
	@(cd ${WRKDIR}/${GIMP_DATA} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})

.include "../../mk/bsd.pkg.mk"
