# $NetBSD: Makefile,v 1.11 2015/09/03 03:12:11 dsainty Exp $
#

PKGNAME=		picprg-2.3d
DISTNAME=		${PKGNAME_NOREV:S/-//}
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		http://www.finitesite.com/d3jsys/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.finitesite.com/d3jsys/
COMMENT=		Parallel port PIC programmer

# The programmer makes direct I/O bus accesses via the i386 in/out
# instructions.  The program has been patched to work on NetBSD only,
# via the i386_set_ioperm() interface.
#
ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picprg ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/picprg
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/picprg
	${INSTALL_DATA} ${WRKSRC}/README.BAJ ${DESTDIR}${PREFIX}/share/doc/picprg

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
