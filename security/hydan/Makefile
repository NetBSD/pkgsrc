# $NetBSD: Makefile,v 1.1.1.1 2004/08/13 10:26:03 agc Exp $

DISTNAME=	hydan-0.13
CATEGORIES=	security
MASTER_SITES=	http://crazyboy.com/hydan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://crazyboy.com/hydan/
COMMENT=	Steganography tool for covert comms, signing and watermarking

ONLY_FOR_PLATFORM=	NetBSD-*-i386 FreeBSD-*-i386 Linux-*-i386

WRKSRC=		${WRKDIR}/hydan

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydan ${PREFIX}/bin
	cd ${PREFIX}/bin && 						\
		${RM} -f hydan-decode hydan-stats && 			\
		${LN} -s hydan hydan-decode && 				\
		${LN} -s hydan hydan-stats
	${INSTALL_DATA_DIR} ${PREFIX}/share/hydan
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/hydan
	${INSTALL_DATA} ${WRKSRC}/README.details ${PREFIX}/share/hydan

.include "../../mk/bsd.pkg.mk"
