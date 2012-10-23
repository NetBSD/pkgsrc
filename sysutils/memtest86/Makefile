# $NetBSD: Makefile,v 1.24 2012/10/23 19:51:12 asau Exp $
#

DISTNAME=		memtest86-4.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_FREEBSD}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		Thorough, stand alone memory test for x86 arch
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

USE_TOOLS+=		gmake

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest.bin ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/memtest
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/memtest

.include "../../mk/bsd.pkg.mk"
