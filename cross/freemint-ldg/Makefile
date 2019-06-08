# $NetBSD: Makefile,v 1.3 2019/06/08 10:53:28 rillig Exp $

DISTNAME=		ldg-SVN-20131104
PKGNAME=		cross-freemint-${DISTNAME:S/SVN-//}
CATEGORIES=		cross
MASTER_SITES=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/archives/
MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		http://vincent.riviere.free.fr/soft/m68k-atari-mint/
COMMENT=		LDG for FreeMiNT
EXTRACT_SUFX=		.tar.bz2
LICENSE=		gnu-lgpl-v2.1

SUBST_CLASSES+=			dos_eol
SUBST_MESSAGE.dos_eol=		Removing DOS line-ends
SUBST_STAGE.dos_eol=		post-extract
SUBST_FILES.dos_eol=		src/ldgmgr/gcc.mak
SUBST_FILES.dos_eol+=		src/ldgd/gcc.mak
SUBST_FILTER_CMD.dos_eol=	${TR} -d '\r'


DEPENDS+=	cross-freemint-gcc-[0-9]*:../../cross/freemint-gcc

USE_TOOLS+=		gmake

FREEMINT_PREFIX=	${PREFIX}/cross-freemint

BUILD_DIRS=		src/devel

MAKE_FLAGS+=		FREEMINT_PREFIX=${FREEMINT_PREFIX}
BUILD_TARGET=		cross

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
