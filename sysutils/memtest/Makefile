# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 11:28:32 agc Exp $
#

DISTNAME=		memtest86-2.5
PKGNAME=		memtest-2.5
CATEGORIES=		sysutils
MASTER_SITES=		http://reality.sgi.com/cbrady_denver/memtest86/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://reality.sgi.com/cbrady_denver/memtest86/
COMMENT=		thorough, stand alone memory test for x86 arch

BUILD_DEPENDS+=		bcc-95.3.12:../../devel/bcc

USE_GMAKE=		yes
ONLY_FOR_PLATFORM=	NetBSD-*-i386

post-patch:
	${CP} ${FILESDIR}/linkage.h ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/mdec
	${CP} ${WRKSRC}/memtest.bin ${PREFIX}/mdec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/memtest
	${CP} ${WRKSRC}/README ${PREFIX}/share/doc/memtest

.include "../../mk/bsd.pkg.mk"
