# $NetBSD: Makefile,v 1.1.1.1 2010/09/09 02:15:22 joerg Exp $
#

DISTNAME=		openjpeg_v1_3
PKGNAME=		openjpeg-1.3
CATEGORIES=		graphics
MASTER_SITES=		http://openjpeg.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openjpeg.org
COMMENT=		JPEG 2000 library

PKG_DESTDIR_SUPPORT=	user-destdir
LICENSE=		2-clause-bsd

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	include lib

WRKSRC=		${WRKDIR}/OpenJPEG_v1_3

SRCS=  bio.c cio.c dwt.c event.c image.c j2k.c j2k_lib.c jp2.c jpt.c mct.c \
  mqc.c openjpeg.c pi.c raw.c t1.c t2.c tcd.c tgt.c

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DHAVE_POSIX_MEMALIGN

do-build:
	${RUN} cd ${WRKSRC}/libopenjpeg && for src in ${SRCS}; do \
		libtool --mode=compile ${CC} ${CFLAGS} -c $$src; \
	done
	${RUN} cd ${WRKSRC}/libopenjpeg && libtool --mode=link \
	    ${CC} -o libopenjpeg.la ${SRCS:C/\.c$/.lo/} \
	    -rpath ${PREFIX}/lib -version-info 0:0:0

do-install:
	libtool --mode=install ${INSTALL_LIB} \
	    ${WRKSRC}/libopenjpeg/libopenjpeg.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libopenjpeg/openjpeg.h \
	    ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
