# $NetBSD: Makefile,v 1.5 2002/10/21 12:59:57 wiz Exp $
#

DISTNAME=		memtest86-2.9
CATEGORIES=		sysutils
MASTER_SITES=		http://www.memtest86.com/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		thorough, stand alone memory test for x86 arch

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
