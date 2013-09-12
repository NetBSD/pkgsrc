# $NetBSD: Makefile,v 1.1 2013/09/12 14:06:21 ryoon Exp $

DISTNAME=	 	ldg-SVN-20121005
PKGNAME=		cross-freemint-${DISTNAME:S/SVN-//}
CATEGORIES=		cross
MASTER_SITES=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/
MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/
COMMENT=		LDG for FreeMiNT
EXTRACT_SUFX=		.tar.bz2

DEPENDS+=	cross-freemint-gcc-[0-9]*:../../cross/freemint-gcc

USE_TOOLS+=		gmake

FREEMINT_PREFIX=	${PREFIX}/cross-freemint

BUILD_DIRS=		src/devel

MAKE_FLAGS+=		FREEMINT_PREFIX=${FREEMINT_PREFIX}

COMMON_CFLAGS=		-W -Wall -O2 -fomit-frame-pointer -I../../include -I.. -I.

INSTALLATION_DIRS=	cross-freemint/lib/m68020-60 \
			cross-freemint/lib/m5475

# XXX I cannot split install stage from build stage.
do-install:
	# m68000 library
	cd ${WRKSRC}/${BUILD_DIRS} && \
		make -f gcc.mak CROSS=yes ${MAKE_FLAGS} \
		CFLAGS="${COMMON_CFLAGS}"
	${INSTALL_LIB} ${WRKSRC}/lib/gcc/libldg.a \
		${DESTDIR}${FREEMINT_PREFIX}/lib
	cd ${WRKSRC}/${BUILD_DIRS} && make clean

	# m68020-60 library
	cd ${WRKSRC}/${BUILD_DIRS} && \
		make -f gcc.mak CROSS=yes ${MAKE_FLAGS} \
		CFLAGS="-m68020-60 ${COMMON_CFLAGS}"
	${INSTALL_LIB} ${WRKSRC}/lib/gcc/libldg.a \
		${DESTDIR}${FREEMINT_PREFIX}/lib/m68020-60
	cd ${WRKSRC}/${BUILD_DIRS} && make clean

	# m5475 library
	cd ${WRKSRC}/${BUILD_DIRS} && \
		make -f gcc.mak CROSS=yes ${MAKE_FLAGS} \
		CFLAGS="-mcpu=5475 ${COMMON_CFLAGS}"
	${INSTALL_LIB} ${WRKSRC}/lib/gcc/libldg.a \
		${DESTDIR}${FREEMINT_PREFIX}/lib/m5475

.include "../../cross/freemint-gemlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
