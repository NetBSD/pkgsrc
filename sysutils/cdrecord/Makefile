# $NetBSD: Makefile,v 1.38 2001/08/07 11:23:56 drochner Exp $

DISTNAME=	cdrtools-1.10
PKGNAME=	cdrecord-1.10
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/cdrecord.html
COMMENT=	This program allows you to create CD's on a CD-Recorder

CONFLICTS=	mkisofs-*
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/a.*//}
TARGET_ARCH=	${MACHINE_ARCH}-netbsd-cc
TARGET_DIR=	OBJ/${TARGET_ARCH}
#override ARCH to avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""
TBL?=		tbl

post-extract:
	@cd ${WRKSRC}; \
	    ${MV} mkisofs/mkisofs.8 mkisofs/mkisofs.tbl

do-configure:
	${MKDIR} ${WRKSRC}/include/sys
	${LN} -fs /usr/include/soundcard.h ${WRKSRC}/include/sys
	cd ${WRKSRC}/RULES; \
	${TEST} -f netbsd-cc.rul || ${MV} i386-netbsd-cc.rul netbsd-cc.rul; \
	${TEST} -f netbsd-gcc.rul || ${MV} i386-netbsd-gcc.rul netbsd-gcc.rul; \
	${LN} -sf netbsd-gcc.rul ${MACHINE}-netbsd-gcc.rul; \
	${LN} -sf netbsd-cc.rul ${TARGET_ARCH}.rul

post-build:
	${TBL} ${WRKSRC}/mkisofs/mkisofs.tbl > ${WRKSRC}/mkisofs/mkisofs.8

do-install:
	cd ${WRKSRC}/cdda2wav; \
	    ${INSTALL_PROGRAM} ${TARGET_DIR}/cdda2wav ${PREFIX}/bin; \
	    ${INSTALL_MAN} cdda2wav.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/cdrecord; \
	    ${INSTALL_PROGRAM} ${TARGET_DIR}/cdrecord ${PREFIX}/bin; \
	    ${INSTALL_MAN} cdrecord.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/mkisofs; \
	    ${INSTALL_PROGRAM} ${TARGET_DIR}/mkisofs ${PREFIX}/bin; \
	    ${INSTALL_MAN} mkisofs.8 ${PREFIX}/man/man8
	cd ${WRKSRC}/misc; \
	    ${INSTALL_PROGRAM} ${TARGET_DIR}/readcd ${PREFIX}/bin; \
	    ${INSTALL_MAN} readcd.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
