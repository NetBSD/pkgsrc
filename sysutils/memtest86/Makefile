# $NetBSD: Makefile,v 1.3.2.1 2002/06/23 19:00:20 jlam Exp $
#

DISTNAME=		memtest86-2.9
CATEGORIES=		sysutils
MASTER_SITES=		http://www.memtest86.com/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		thorough, stand alone memory test for x86 arch

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_GMAKE=		yes

post-patch:
	${CP} ${FILESDIR}/linkage.h ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${CP} ${WRKSRC}/memtest.bin ${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/memtest
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/memtest

.include "../../devel/binutils/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
