# $NetBSD: Makefile,v 1.3 2002/08/26 19:38:05 jlam Exp $

PKGNAME=	aalib-x11-${BASE_VERS}
CATEGORIES+=	x11
PKGREVISION=	1

COMMENT=	ASCII Art library with X11 support

USE_BUILDLINK2=		# defined
USE_X11=		# defined

ALL_TARGET=		libaa-x11.la
INSTALL_TARGET=		install-libLTLIBRARIES

post-patch:
	for file in ${WRKSRC}/src/Makefile.in; do			\
		${SED}	-e "s,libaa\.la,libaa-x11.la,g"			\
			-e "s,libaa_la,libaa_x11_la,g"			\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done

do-build:
	cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aalib-config ${PREFIX}/bin/aalib-x11-config
	${INSTALL_DATA} ${WRKSRC}/src/aalib.h ${PREFIX}/include/aalib-x11.h
	cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../graphics/aalib/Makefile.common"
