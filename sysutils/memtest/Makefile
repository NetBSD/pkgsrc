# $NetBSD: Makefile,v 1.3 2001/12/25 22:08:52 wiz Exp $
#

DISTNAME=		memtest86-2.8a
PKGNAME=		memtest-2.8
CATEGORIES=		sysutils
MASTER_SITES=		http://www.memtest86.com/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.memtest86.com/
COMMENT=		thorough, stand alone memory test for x86 arch

USE_GMAKE=		yes
ONLY_FOR_PLATFORM=	NetBSD-*-i386
WRKSRC=			${WRKDIR}/${DISTNAME:S/a$//}

post-patch:
	${CP} ${FILESDIR}/linkage.h ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${CP} ${WRKSRC}/memtest.bin ${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/memtest
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/memtest

.include "../../mk/bsd.pkg.mk"
