# $NetBSD: Makefile,v 1.7 1998/11/12 15:19:59 agc Exp $

DISTNAME=		macutil2.0b3
PKGNAME=		macutil-2.0b3
CATEGORIES=		archivers
MASTER_SITES=		ftp://ftp.cwi.nl/pub/dik/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		mycroft@NetBSD.ORG

MAKEFILE=		makefile
EXTRACT_CMD=		zcat
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

WRKSRC=			${WRKDIR}/macutil

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/macunpack/macunpack \
			   ${WRKSRC}/hexbin/hexbin \
			   ${WRKSRC}/mixed/macsave \
			   ${WRKSRC}/mixed/macstream \
			   ${WRKSRC}/binhex/binhex \
			   ${WRKSRC}/comm/tomac \
			   ${WRKSRC}/comm/frommac ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/macunpack.1 \
		       ${WRKSRC}/man/hexbin.1 \
		       ${WRKSRC}/man/macsave.1 \
		       ${WRKSRC}/man/macstream.1 \
		       ${WRKSRC}/man/binhex.1 \
		       ${WRKSRC}/man/tomac.1 \
		       ${WRKSRC}/man/frommac.1 \
		       ${WRKSRC}/man/macutil.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
