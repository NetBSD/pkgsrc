# $NetBSD: Makefile,v 1.9 1998/04/15 20:48:12 tron Exp $

DISTNAME=	gimp-0.99.26
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v0.99/v0.99.26/  \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gimp/v0.99/v0.99.26/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gimp/v0.99/v0.99.26/
GIMP_DATA=	gimp-data-extras-0.99a
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${GIMP_DATA}${EXTRACT_SUFX}

MAINTAINER=	bsieker@techfak.uni-bielefeld.de

BUILD_DEPENDS=	install-info:${PORTSDIR}/devel/gtexinfo
LIB_DEPENDS=	jpeg.7.:${PORTSDIR}/graphics/jpeg \
		mpeg.1.2:${PORTSDIR}/graphics/mpeg-lib \
		png.0.96:${PORTSDIR}/graphics/png \
		tiff.3.4:${PORTSDIR}/graphics/tiff \
		gtk.1.0:${PORTSDIR}/x11/gtk \
		Xpm.4.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

CFLAGS=		-pipe -O2 -I${LOCALBASE}/include -I${X11BASE}/include

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
