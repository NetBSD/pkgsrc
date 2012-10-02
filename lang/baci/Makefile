# $NetBSD: Makefile,v 1.16 2012/10/02 20:11:35 asau Exp $
#

DISTNAME=	bacisrc
PKGNAME=	baci-20000725
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_BACKUP}
DISTFILES=	bacisrc.tar.gz \
		bacidoc.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mines.edu/fs_home/tcamp/baci/
COMMENT=	Ben-Ari Concurrent Interpreter

USE_TOOLS+=	flex bison:run

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/ccomp && ${MAKE}
	cd ${WRKSRC}/disasm && ${MAKE}
	cd ${WRKSRC}/interp && ${MAKE}
	cd ${WRKSRC}/pascomp && ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ccomp/bacc ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/disasm/badis ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/interp/bainterp ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/pascomp/bapas ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/baci
	${INSTALL_DATA} ${WRKDIR}/bacidoc/* ${DESTDIR}${PREFIX}/share/doc/baci

.include "../../mk/bsd.pkg.mk"
