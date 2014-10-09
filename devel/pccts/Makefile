# $NetBSD: Makefile,v 1.22 2014/10/09 14:06:30 wiz Exp $
#

DISTNAME=	pccts133mr33
PKGNAME=	pccts-1.33.33
CATEGORIES=	devel
MASTER_SITES=	http://www.polhode.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	david@maxwell.net
HOMEPAGE=	http://www.polhode.com/pccts.html
COMMENT=	Purdue Compiler Construction Tool Set

WRKSRC=		${WRKDIR}/pccts
DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_FILE=	makefile
BUILD_TARGET=

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/antlr ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dlg ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/genmk ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sor ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pccts
	${INSTALL_MAN} ${WRKSRC}/CHANGES_FROM_131.txt \
		${WRKSRC}/CHANGES_FROM_133.txt \
		${WRKSRC}/CHANGES_FROM_133_BEFORE_MR13.txt \
		${WRKSRC}/KNOWN_PROBLEMS.txt \
		${WRKSRC}/RIGHTS ${WRKSRC}/history.txt \
		${DESTDIR}${PREFIX}/share/doc/pccts/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/pccts
	${INSTALL_MAN} ${WRKSRC}/h/*.h ${DESTDIR}${PREFIX}/include/pccts/
	${INSTALL_MAN} ${WRKSRC}/h/*.c ${DESTDIR}${PREFIX}/include/pccts/
	${INSTALL_MAN} ${WRKSRC}/h/*.cpp ${DESTDIR}${PREFIX}/include/pccts/

.include "../../mk/bsd.pkg.mk"
