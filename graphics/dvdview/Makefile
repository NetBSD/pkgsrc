# $NetBSD: Makefile,v 1.5 2001/11/29 01:12:35 hubertf Exp $

DISTNAME=	dvdview1.1.0
PKGNAME=	dvdview-1.1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/arch/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://rachmaninoff.informatik.uni-mannheim.de/dvdview/
COMMENT=	Software only MPEG-1/2 video decoder

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

.include "../../mk/bsd.prefs.mk"

.if !defined(WRKSRC)
do-configure:
	@${SETENV} WRKSRC=${WRKDIR}/ulib ${MAKE} ${.TARGET}
	@${SETENV} WRKSRC=${WRKDIR}/dvdview ${MAKE} ${.TARGET}

do-build:
	@${SETENV} WRKSRC=${WRKDIR}/ulib ${MAKE} ${.TARGET}
	@${SETENV} WRKSRC=${WRKDIR}/dvdview/src ${MAKE} ${.TARGET}
.endif

ALL_TARGET=	# empty
WRKSRC?=	${WRKDIR}/dvdview
.if (${OPSYS} == SunOS)
MAKE_ENV+=	RTLIB=-lrt
.else
MAKE_ENV+=	RTLIB=
.endif

.if (${OPSYS} != "Linux") && (${MACHINE_ARCH} == i386)
post-configure:
	cd ${WRKSRC} && \
	for FILE in ../ulib/config.h src/config.h; do \
	  ${CP} $$FILE $${FILE}.old; \
	  ${SED} -e 's/#define ENABLE_MMX 1/#undef ENABLE_MMX/' \
	    $${FILE}.old >$${FILE}; \
	done
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dvdview ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dvdview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dvdview

.include "../../mk/bsd.pkg.mk"
