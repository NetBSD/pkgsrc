# $NetBSD: Makefile,v 1.27 2018/01/29 12:16:29 maya Exp $
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
HOMEPAGE=		https://www.memtest86.com/
COMMENT=		Stand alone memory test for x86 arch (no longer maintained)
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

FORTIFY_SUPPORTED=	no
SSP_SUPPORTED=		no

USE_TOOLS+=		gmake

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA} ${WRKSRC}/memtest.bin ${DESTDIR}${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/memtest
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/memtest

.include "../../mk/bsd.pkg.mk"
