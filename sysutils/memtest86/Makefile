# $NetBSD: Makefile,v 1.10 2003/12/24 09:53:50 jmmv Exp $
#

DISTNAME=		memtest86-2.9
CATEGORIES=		sysutils
MASTER_SITES=		http://www.memtest86.com/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		Thorough, stand alone memory test for x86 arch

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

post-patch:
	${CP} ${FILESDIR}/linkage.h ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${CP} ${WRKSRC}/memtest.bin ${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/memtest
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/memtest

.include "../../devel/binutils/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
