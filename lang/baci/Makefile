# $NetBSD: Makefile,v 1.6 2001/05/09 13:09:24 agc Exp $
#

DISTNAME=	bacisrc
PKGNAME=	baci-20000725
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_BACKUP}
DISTFILES=	bacisrc.tar.gz \
		bacidoc.tar.gz

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.mines.edu/fs_home/tcamp/baci/
COMMENT=	Ben-Ari Concurrent Interpreter

DEPENDS+=	bison-*:../../devel/bison

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
		${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/baci
		${INSTALL_DATA} ${WRKDIR}/bacidoc/* ${LOCALBASE}/share/doc/baci
		${CP} ${PKGDIR}/PLIST ${WRKDIR}

.include "../../mk/bsd.pkg.mk"
