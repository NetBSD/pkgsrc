# $NetBSD: Makefile,v 1.23 2021/05/31 12:05:52 wiz Exp $

DISTNAME=	pccts133mr33
PKGNAME=	pccts-1.33.33
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.polhode.com/
EXTRACT_SUFX=	.zip

MAINTAINER=	david@maxwell.net
HOMEPAGE=	http://www.polhode.com/pccts.html
COMMENT=	Purdue Compiler Construction Tool Set
LICENSE=	public-domain

WRKSRC=		${WRKDIR}/pccts
DIST_SUBDIR=	${PKGNAME_NOREV}

MAKE_FILE=	makefile
MAKE_FLAGS+=	COPT=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
BUILD_TARGET=

INSTALLATION_DIRS=	bin share/doc/pccts include/pccts

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/antlr ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dlg ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/genmk ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sor ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/CHANGES_FROM_131.txt \
		${WRKSRC}/CHANGES_FROM_133.txt \
		${WRKSRC}/CHANGES_FROM_133_BEFORE_MR13.txt \
		${WRKSRC}/KNOWN_PROBLEMS.txt \
		${WRKSRC}/RIGHTS ${WRKSRC}/history.txt \
		${DESTDIR}${PREFIX}/share/doc/pccts/
	${INSTALL_MAN} ${WRKSRC}/h/*.h ${DESTDIR}${PREFIX}/include/pccts/
	${INSTALL_MAN} ${WRKSRC}/h/*.c ${DESTDIR}${PREFIX}/include/pccts/
	${INSTALL_MAN} ${WRKSRC}/h/*.cpp ${DESTDIR}${PREFIX}/include/pccts/

.include "../../mk/bsd.pkg.mk"
