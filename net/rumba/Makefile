# $NetBSD: Makefile,v 1.3 1998/06/03 13:16:57 agc Exp $
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
MAN8=		smbmount.8

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
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.rumba
.endif
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8

.include <../../mk/bsd.pkg.mk>
