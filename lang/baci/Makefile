# $NetBSD: Makefile,v 1.1.1.1 2000/07/25 12:44:33 wulf Exp $
#

DISTNAME=	bacisrc
PKGNAME=	baci-20000725
CATEGORIES=	lang
MASTER_SITES=	http://www.mines.edu/fs_home/tcamp/baci/
DISTFILES=	bacisrc.tar.gz \
		bacidoc.tar.gz

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.mines.edu/fs_home/tcamp/baci/

PLIST_SRC=      ${WRKDIR}/PLIST

do-build:
		cd ${WRKSRC}/ccomp && ${MAKE}
		cd ${WRKSRC}/disasm && ${MAKE}
		cd ${WRKSRC}/interp && ${MAKE}
		cd ${WRKSRC}/pascomp && ${MAKE}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ccomp/bacc ${LOCALBASE}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/disasm/badis ${LOCALBASE}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/interp/bainterp ${LOCALBASE}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/pascomp/bapas ${LOCALBASE}/bin
		${MKDIR} ${LOCALBASE}/share/doc/baci
		${CP} ${WRKDIR}/bacidoc/* ${LOCALBASE}/share/doc/baci
		${CP} ${PKGDIR}/PLIST ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
