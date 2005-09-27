# $NetBSD: Makefile,v 1.3 2005/09/27 11:25:36 dsainty Exp $
#

PKGNAME=		picprg-2.3d
DISTNAME=		${PKGNAME:S/-//}
CATEGORIES=		devel
MASTER_SITES=		http://www.finitesite.com/d3jsys/

MAINTAINER=		dsainty@NetBSD.org
HOMEPAGE=		http://www.finitesite.com/d3jsys/
COMMENT=		Parallel port PIC programmer

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picprg ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/picprg
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/picprg
	${INSTALL_DATA} ${WRKSRC}/README.BAJ ${PREFIX}/share/doc/picprg

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
