# $NetBSD: Makefile,v 1.27 2000/03/03 15:22:15 scw Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 23:55:31 asami Exp
#

DISTNAME=	cdrecord-1.8
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.fokus.gmd.de/nthp/employees/schilling/cdrecord.html

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C/a.*//}
TARGET_ARCH=	${MACHINE}-netbsd-cc
TARGET_DIR=	OBJ/${TARGET_ARCH}

post-configure:
	${MKDIR} ${WRKSRC}/include/sys
	${LN} -fs /usr/include/soundcard.h ${WRKSRC}/include/sys
	cd ${WRKSRC}/RULES ; \
	${TEST} -f netbsd-cc.rul || ${MV} i386-netbsd-cc.rul netbsd-cc.rul; \
	${TEST} -f netbsd-gcc.rul || ${MV} i386-netbsd-gcc.rul netbsd-gcc.rul; \
	${LN} -sf netbsd-gcc.rul ${MACHINE}-netbsd-gcc.rul; \
	${LN} -sf netbsd-cc.rul ${TARGET_ARCH}.rul;

do-install:
	cd ${WRKSRC}/cdda2wav; \
	${INSTALL_PROGRAM} ${TARGET_DIR}/cdda2wav ${PREFIX}/bin; \
	${INSTALL_MAN} cdda2wav.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/cdrecord; \
	${INSTALL_PROGRAM} ${TARGET_DIR}/cdrecord ${PREFIX}/bin; \
	${INSTALL_MAN} cdrecord.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/misc/${TARGET_DIR}/readcd ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
