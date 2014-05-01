# $NetBSD: Makefile,v 1.25 2014/05/01 15:07:31 gdt Exp $
#

DISTNAME=		memtest86-4.0
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_FREEBSD}

# Newer versions of this software appear to be available only as
# binaries.
# There is a 4.0s on the FreeBSD distfiles site, apparently with
# bugfixes.
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		Stand alone memory test for x86 arch (no longer maintained)
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
