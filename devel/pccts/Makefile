# $NetBSD: Makefile,v 1.8 2002/02/25 04:47:22 jlam Exp $
#

DISTNAME=	pccts133mr22
PKGNAME=	pccts-1.33.22
CATEGORIES=	devel
MASTER_SITES=	http://www.polhode.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	David Maxwell <david@maxwell.net>
HOMEPAGE=	http://www.polhode.com/pccts.html
COMMENT=	Purdue Compiler Construction Tool Set

DIST_SUBDIR=	${PKGNAME}

WRKSRC=		${WRKDIR}/pccts
MAKEFILE=	makefile
ALL_TARGET=

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
