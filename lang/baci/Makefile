# $NetBSD: Makefile,v 1.10 2005/06/17 04:49:47 jlam Exp $
#

DISTNAME=	bacisrc
PKGNAME=	baci-20000725
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_BACKUP}
DISTFILES=	bacisrc.tar.gz \
		bacidoc.tar.gz

MAINTAINER=	wulf@NetBSD.org
HOMEPAGE=	http://www.mines.edu/fs_home/tcamp/baci/
COMMENT=	Ben-Ari Concurrent Interpreter

DEPENDS+=	bison-[0-9]*:../../devel/bison

PLIST_SRC=      ${WRKDIR}/PLIST

INSTALLATION_DIRS=	bin

do-build:
		cd ${WRKSRC}/ccomp && ${MAKE}
		cd ${WRKSRC}/disasm && ${MAKE}
		cd ${WRKSRC}/interp && ${MAKE}
		cd ${WRKSRC}/pascomp && ${MAKE}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/ccomp/bacc ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/disasm/badis ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/interp/bainterp ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/pascomp/bapas ${PREFIX}/bin
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/baci
		${INSTALL_DATA} ${WRKDIR}/bacidoc/* ${PREFIX}/share/doc/baci
		${CP} ${PKGDIR}/PLIST ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
