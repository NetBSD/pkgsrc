# $NetBSD: Makefile,v 1.21 2001/01/13 18:39:44 jlam Exp $

DISTNAME=       imap-2000a
PKGNAME=        imap-uw-2000a
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.washington.edu/imap/

USE_LIBTOOL=	# defined

MESSAGE_FILE=	${WRKDIR}/MESSAGE

INST_PROG=	${LIBTOOL} ${INSTALL_PROGRAM}
INST_LIB=	${LIBTOOL} ${INSTALL_DATA}
INC_DIR=	${PREFIX}/include/c-client
DOC_DIR=	${PREFIX}/share/doc/imap-uw

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
ALL_TARGET=	gso
.else
ALL_TARGET=	neb
.endif

NO_CONFIGURE=	# defined

USE_SSL=	# defined
MAKE_ENV+=	SSLBASE="${SSLBASE}"
MAKE_ENV+=	SSLCERTS="${SSLCERTS}"
ALL_TARGET+=	CC="${LIBTOOL} ${CC}"
ALL_TARGET+=	EXTRACFLAGS="${CFLAGS}"
ALL_TARGET+=	SPECIALAUTHENTICATORS="ssl"

post-build:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${WRKSRC}/src/imapd/imapd.8c > ${WRKDIR}/imapd.8
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${WRKSRC}/src/ipopd/ipopd.8c > ${WRKDIR}/ipopd.8

pre-install:
	${SED} -e 's|@PREFIX@|${PREFIX}|g' \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

do-install:
	${INST_LIB} ${WRKSRC}/c-client/libimapuw.la ${PREFIX}/lib
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
	${INSTALL_DATA_DIR} ${INC_DIR}
	for i in linkage.h mail.h rfc822.h misc.h imap4r1.h osdep.h smtp.h \
		nntp.h env_unix.h fs.h ftl.h nl.h  tcp.h env.h linkage.c; \
	do \
		${INSTALL_DATA} ${WRKSRC}/c-client/$$i ${INC_DIR}; \
	done

.include "../../mk/bsd.pkg.mk"
