# $NetBSD: Makefile,v 1.10 2001/02/17 18:19:34 wiz Exp $
# $FreeBSD Id: Makefile,v 1.2 1997/07/21 19:28:46 max Exp
#

DISTNAME=	rumba.0.6.s
PKGNAME=	rumba-0.6
CATEGORIES=	net
MASTER_SITES=	ftp://hal.kph.tuwien.ac.at/pub/NeXT/tools/rumba/ \
		ftp://next-ftp.peak.org/pub/next/apps/utils/networks/
EXTRACT_SUFX=	.gnutar.gz

MAINTAINER=	tron@netbsd.org
COMMENT=	Userland smbfs --- SMB to NFS protocol converter

MAKE_ENV=	PWD=${WRKSRC}

.include "../../mk/bsd.prefs.mk"

post-extract:
	@${MKDIR} ${WRKDIR}/unrumba
	@${LN} -s ${FILESDIR}/unrumba.c ${WRKDIR}/unrumba
	@${LN} -s ${FILESDIR}/Makefile.unrumba ${WRKDIR}/unrumba/Makefile

post-build:
	cd ${WRKDIR}/unrumba && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rumba ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKDIR}/unrumba/unrumba ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/share/doc/rumba
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rumba/README
	${INSTALL_MAN} ${WRKSRC}/smbmount.8 ${PREFIX}/man/man8/rumba.8

.include "../../mk/bsd.pkg.mk"
