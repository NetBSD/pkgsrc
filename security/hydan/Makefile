# $NetBSD: Makefile,v 1.8 2014/02/12 23:18:32 tron Exp $

DISTNAME=	hydan-0.13
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://crazyboy.com/hydan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://crazyboy.com/hydan/
COMMENT=	Steganography tool for covert comms, signing and watermarking

ONLY_FOR_PLATFORM=	NetBSD-*-i386 FreeBSD-*-i386 Linux-*-i386

WRKSRC=		${WRKDIR}/hydan

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hydan ${DESTDIR}${PREFIX}/bin
	cd ${DESTDIR}${PREFIX}/bin && 					\
		${RM} -f hydan-decode hydan-stats && 			\
		${LN} -s hydan hydan-decode && 				\
		${LN} -s hydan hydan-stats
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/hydan
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/hydan
	${INSTALL_DATA} ${WRKSRC}/README.details ${DESTDIR}${PREFIX}/share/hydan

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
