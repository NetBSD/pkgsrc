# $NetBSD: Makefile,v 1.5 2003/10/26 06:50:10 grant Exp $

PKGNAME=	aalib-x11-${BASE_VERS}
CATEGORIES+=	x11
PKGREVISION=	2

COMMENT=	ASCII Art library with X11 support

USE_BUILDLINK2=		# defined
USE_X11=		# defined

ALL_TARGET=		libaa-x11.la
INSTALL_TARGET=		install-libLTLIBRARIES

# We need to correct the aalib-config script to return "-laa-x11" instead
# of "-laa".
#
BUILDLINK_TRANSFORM+=	l:aa:aa-x11

post-patch:
	for file in ${WRKSRC}/src/Makefile.in; do			\
		${SED}	-e "s,libaa\.la,libaa-x11.la,g"			\
			-e "s,libaa_la,libaa_x11_la,g"			\
			$${file} > $${file}.fixed;			\
		${MV} -f $${file}.fixed $${file};			\
	done
	@for f in `${FIND} ${WRKSRC} -name '*.[ch]'`; do		\
		${SED} -e "s|<malloc.h>|<stdlib.h>|g" $$f > $$f.patch	\
		&& ${MV} $$f.patch $$f;					\
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
