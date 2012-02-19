# $NetBSD: Makefile,v 1.23 2012/02/19 11:14:32 obache Exp $
#

DISTNAME=		memtest86-4.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_FREEBSD}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		Thorough, stand alone memory test for x86 arch
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest.bin ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/memtest
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/memtest

.include "../../mk/bsd.pkg.mk"
