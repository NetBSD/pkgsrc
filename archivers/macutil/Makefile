# $NetBSD: Makefile,v 1.4 1998/04/15 10:38:08 agc Exp $

DISTNAME=	macutil
PKGNAME=	macutil-2.0b3
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.cwi.nl/pub/dik/
DISTFILES=	macutil2.0b3.shar.Z

MAINTAINER=	mycroft@NetBSD.ORG

MAKEFILE=	makefile

MAN1=		macunpack.1 hexbin.1 macsave.1 macstream.1 binhex.1 tomac.1 \
		frommac.1 macutil.1

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && ${GUNZIP_CMD} <${_DISTDIR}/${DISTFILES} | sh

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
