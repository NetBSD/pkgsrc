# $NetBSD: Makefile,v 1.5 1998/08/25 15:52:02 tv Exp $
# $FreeBSD Id: Makefile,v 1.2 1997/07/21 19:28:46 max Exp
#

DISTNAME=	rumba.0.6.s
PKGNAME=	rumba-0.6
CATEGORIES=	net
MASTER_SITES=	ftp://hal.kph.tuwien.ac.at/pub/NeXT/tools/rumba/ \
		ftp://next-ftp.peak.org/pub/next/apps/utils/networks/
EXTRACT_SUFX=	.gnutar.gz

MAINTAINER=	tron@netbsd.org

MAKE_ENV=	PWD=${WRKSRC}

.include "../../mk/bsd.prefs.mk"

post-extract:
	@${MKDIR} ${WRKDIR}/unrumba
	@${LN} -s ${FILESDIR}/unrumba.c ${WRKDIR}/unrumba
	@${LN} -s ${FILESDIR}/Makefile.unrumba ${WRKDIR}/unrumba/Makefile

post-build:
	cd ${WRKDIR}/unrumba && make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rumba ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKDIR}/unrumba/unrumba ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.rumba
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8/rumba.8

.include "../../mk/bsd.pkg.mk"
