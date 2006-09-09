# $NetBSD: Makefile,v 1.18 2006/09/09 02:41:58 obache Exp $
#

DISTNAME=	pccts133mr22
PKGNAME=	pccts-1.33.22
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.polhode.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	david@maxwell.net
HOMEPAGE=	http://www.polhode.com/pccts.html
COMMENT=	Purdue Compiler Construction Tool Set

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}/pccts
DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_FILE=	makefile
BUILD_TARGET=


INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/antlr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dlg ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/genmk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sor ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pccts
	${INSTALL_MAN} ${WRKSRC}/CHANGES_FROM_131.txt \
		${WRKSRC}/CHANGES_FROM_133.txt \
		${WRKSRC}/CHANGES_FROM_133_BEFORE_MR13.txt \
		${WRKSRC}/KNOWN_PROBLEMS.txt \
		${WRKSRC}/RIGHTS ${WRKSRC}/history.txt \
		${PREFIX}/share/doc/pccts/
	${INSTALL_DATA_DIR} ${PREFIX}/include/pccts
	${INSTALL_MAN} ${WRKSRC}/h/*.h ${PREFIX}/include/pccts/
	${INSTALL_MAN} ${WRKSRC}/h/*.c ${PREFIX}/include/pccts/
	${INSTALL_MAN} ${WRKSRC}/h/*.cpp ${PREFIX}/include/pccts/

.include "../../mk/bsd.pkg.mk"
