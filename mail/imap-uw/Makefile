# $NetBSD: Makefile,v 1.12 2000/06/01 11:23:34 rh Exp $
#

DISTNAME=       imap-4.7c2
PKGNAME=        imap-uw-4.7c2
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.washington.edu/imap/

USE_PKGLIBTOOL=	# defined

WRKSRC=		${WRKDIR}/imap-4.7c
MESSAGE_FILE=	${WRKDIR}/MESSAGE

INST_PROG=	${LIBTOOL} ${INSTALL_PROGRAM}
INST_LIB=	${LIBTOOL} ${INSTALL_DATA}
DOC_DIR=	${PREFIX}/share/doc/imap-uw

do-configure:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${WRKSRC}/src/imapd/imapd.8c > ${WRKDIR}/imapd.8
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${WRKSRC}/src/ipopd/ipopd.8c > ${WRKDIR}/ipopd.8
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

do-build:
	cd ${WRKSRC} && ${MAKE} neb PREFIX=${PREFIX} CC="${LIBTOOL} ${CC}"

do-install:
	${INST_LIB} ${WRKSRC}/c-client/libimapuw.la ${PREFIX}/lib
	@${RM} -f ${PREFIX}/lib/libimapuw.a
	${INST_PROG} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INST_PROG} ${WRKSRC}/mtest/mtest ${PREFIX}/sbin
	${LN} -sf ${PREFIX}/libexec/imapd ${PREFIX}/sbin/rimapd
	${INSTALL_MAN} ${WRKDIR}/imapd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/ipopd.8 ${PREFIX}/man/man8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop2d.8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop3d.8
	${INSTALL_DATA_DIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RELNOTES ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOC_DIR}

.include "../../mk/bsd.pkg.mk"
