# $NetBSD: Makefile,v 1.8 1999/02/08 23:31:59 tron Exp $
#

DISTNAME=       imap-4.5
PKGNAME=        imap-uw-4.5
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.washington.edu/imap/

USE_LIBTOOL=	yes

INST_PROG=	${LIBTOOL} ${INSTALL_PROGRAM}
INST_LIB=	${LIBTOOL} ${INSTALL_DATA}
CONFLICTS=	imap-uw-*

MESSAGE_FILE=	${WRKDIR}/.MESSAGE

do-configure:
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/src/imapd/imapd.8c >${WRKSRC}/imapd.8
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/src/ipopd/ipopd.8c >${WRKSRC}/ipopd.8
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${PKGDIR}/MESSAGE >${MESSAGE_FILE}

do-build:
	cd ${WRKSRC} && ${MAKE} neb PREFIX=${PREFIX} CC="${LIBTOOL} ${CC}"

do-install:
	${INST_LIB} ${WRKSRC}/c-client/libimapuw.la ${PREFIX}/lib
	@${RM} -f ${PREFIX}/lib/libimapuw.a
	${INST_PROG} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/mtest/mtest ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/imapd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/ipopd.8 ${PREFIX}/man/man8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop2d.8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop3d.8

.include "../../mk/bsd.pkg.mk"
