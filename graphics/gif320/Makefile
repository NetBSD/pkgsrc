# $NetBSD: Makefile,v 1.11 2008/03/04 15:39:09 jlam Exp $
#

DISTNAME=	gif320-3.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.maths.tcd.ie/pub/sboyle/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GIF file viewer for use with VT-320 terminals

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=	# empty
WRKSRC=		${WRKDIR}/gif320

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gif320 ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gif320.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/README.VMS \
		${DESTDIR}${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${PREFIX}/share/doc/gif320
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/gif320

.include "../../mk/bsd.pkg.mk"
