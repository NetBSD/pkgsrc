# $NetBSD: Makefile,v 1.6 2007/03/26 09:31:10 dsainty Exp $
#

PKGNAME=		picprg-2.3d
DISTNAME=		${PKGNAME_NOREV:S/-//}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.finitesite.com/d3jsys/

MAINTAINER=		dsainty@NetBSD.org
HOMEPAGE=		http://www.finitesite.com/d3jsys/
COMMENT=		Parallel port PIC programmer

# The programmer makes direct I/O bus accesses via the i386 in/out
# instructions.  The program has been patches to work on NetBSD only,
# via the i386_set_ioperm() interface.
ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picprg ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/picprg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/picprg
	${INSTALL_DATA} ${WRKSRC}/README.BAJ ${PREFIX}/share/doc/picprg

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
