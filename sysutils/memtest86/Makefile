# $NetBSD: Makefile,v 1.21 2009/05/22 17:23:06 zafer Exp $
#

DISTNAME=		memtest86-3.4
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_FREEBSD} \
					${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		Thorough, stand alone memory test for x86 arch

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

USE_TOOLS+=		gmake

DIST_SUBDIR=		${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest ${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest.bin ${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/memtest
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/memtest

.include "../../mk/bsd.pkg.mk"
