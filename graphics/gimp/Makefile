# $NetBSD: Makefile,v 1.8 1998/04/15 10:38:25 agc Exp $

DISTNAME=	gimp-0.99.18
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/0.99/0.99.18/  \
		ftp://infosoc.uni-koeln.de/pub/ftp.gimp.org/pub/gimp/0.99/0.99.18/ \
		ftp://ftp.flirble.org/pub/X/gimp/pub/gimp/0.99/0.99.18/

MAINTAINER=	bsieker@techfak.uni-bielefeld.de

GIMP_DATA_MIN=	gimp-data-min-0.99b
GIMP_DATA_EXT=	gimp-data-extras-0.99a

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${GIMP_DATA_MIN}${EXTRACT_SUFX}

.if !defined(GIMP_SMALL_DATA)
DISTFILES+=	${GIMP_DATA_EXT}${EXTRACT_SUFX}
.endif

BUILD_DEPENDS=	install-info:${PORTSDIR}/devel/gtexinfo

LIB_DEPENDS=	jpeg.7.:${PORTSDIR}/graphics/jpeg \
		mpeg.1.2:${PORTSDIR}/graphics/mpeg-lib \
		png.0.96:${PORTSDIR}/graphics/png \
		tiff.3.4:${PORTSDIR}/graphics/tiff \
		tcl80.1.0:${PORTSDIR}/lang/tcl80 \
		tk80.1.0:${PORTSDIR}/x11/tk80 \
		gtk.1.0:${PORTSDIR}/x11/gtk \
		Xpm.4.:${PORTSDIR}/graphics/xpm

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

CFLAGS=		-pipe -O2 -I${LOCALBASE}/include -I${X11BASE}/include

pre-extract:
.if !defined(GIMP_SMALL_DATA)
	@${ECHO_MSG} " "
	@${ECHO_MSG} "    Now installing large data set (5.5 MB)."
	@${ECHO_MSG} " "
	@${ECHO_MSG} "    If you only want the small data set (0.7 MB), abort"
	@${ECHO_MSG} "    and use \"make GIMP_SMALL_DATA=yes\"."
	@${ECHO_MSG} " "
.else
	@${ECHO_MSG} " "
	@${ECHO_MSG} "    Now installing small data set. (0.7 MB)"
	@${ECHO_MSG} " "
.endif

post-configure:
	@${ECHO_MSG} "--> now configuring in ${GIMP_DATA_MIN}"
	@(cd ${WRKDIR}/${GIMP_DATA_MIN} && ${SETENV} ${CONFIGURE_ENV} ${SH} \
		${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} )
.if !defined(GIMP_SMALL_DATA)
	@${ECHO_MSG} "--> now configuring in ${GIMP_DATA_EXT}"
	@(cd ${WRKDIR}/${GIMP_DATA_EXT} && ${SETENV} ${CONFIGURE_ENV} ${SH} \
		${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} )
.endif

PLIST_SRC=	${WRKDIR:T}/.PLIST-src

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' ${LOCALBASE}/info/dir > ${PREFIX}/info/dir; \
	 fi
	@${SED} -e 's|\$${LOCALBASE}|'${LOCALBASE}'|g' < ${PKGDIR}/PLIST > ${PLIST_SRC}

post-install:
	install-info ${PREFIX}/info/pdb.info   ${PREFIX}/info/dir
	@${ECHO_MSG} "--> now installing in ${GIMP_DATA_MIN}"
	@(cd ${WRKDIR}/${GIMP_DATA_MIN} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.if !defined(GIMP_SMALL_DATA)
	@${ECHO_MSG} "--> now installing in ${GIMP_DATA_EXT}"
	@(cd ${WRKDIR}/${GIMP_DATA_EXT} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} \
		${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.endif

.include "../../mk/bsd.pkg.mk"
