# $NetBSD: Makefile,v 1.2 1998/08/04 20:40:50 tron Exp $
#

DISTNAME=       imap-4.2
PKGNAME=        imap-uw-4.2
CATEGORIES=     mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tv@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool

INST_PROG=	${PREFIX}/bin/libtool --mode=install ${INSTALL_PROGRAM}
INST_LIB=	${PREFIX}/bin/libtool --mode=install ${INSTALL_DATA}

do-configure:
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/src/imapd/imapd.8c >${WRKSRC}/imapd.8
	@${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/src/ipopd/ipopd.8c >${WRKSRC}/ipopd.8

do-build:
	cd ${WRKSRC} && ${MAKE} neb PREFIX=${PREFIX} CC="${PREFIX}/bin/libtool ${CC}"

do-install:
	${INST_LIB} ${WRKSRC}/c-client/libimapuw.la ${PREFIX}/lib/
	@${RM} -f ${PREFIX}/lib/libimapuw.a
	${INST_PROG} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec/
	${INST_PROG} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec/
	${INST_PROG} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec/
	${INST_PROG} ${WRKSRC}/mtest/mtest ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/imapd.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/ipopd.8 ${PREFIX}/man/man8/
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop2d.8
	${LN} -sf ipopd.8 ${PREFIX}/man/man8/ipop3d.8

.include "../../mk/bsd.pkg.mk"
