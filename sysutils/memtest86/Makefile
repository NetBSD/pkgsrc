# $NetBSD: Makefile,v 1.12 2004/04/08 13:01:18 ben Exp $
#

DISTNAME=		memtest86-3.1a
CATEGORIES=		sysutils
MASTER_SITES=		http://www.memtest86.com/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		Thorough, stand alone memory test for x86 arch

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${CP} ${WRKSRC}/memtest.bin ${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/memtest
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/memtest

.include "../../devel/binutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
