# $NetBSD: Makefile,v 1.1.1.1 2000/12/16 16:53:14 wiz Exp $
#

DISTNAME=	tavrasm
PKGNAME=	${DISTNAME}-1.15
CATEGORIES=	devel
MASTER_SITES=	http://www.tavrasm.org/

MAINTAINER=	dillo@giga.or.at
HOMEPAGE=	http://www.tavrasm.org/

BUILD_DEPENDS+=	bison:../../devel/bison

WRKSRCTOP=	${WRKDIR}/tavrasm.115
WRKSRC=		${WRKSRCTOP}/src
MAKEFILE=	makefile

DIST_SUBDIR=	${PKGNAME}

do-install:
	${MKDIR} ${PREFIX}/share/doc/tavrasm
	${INSTALL_DATA} ${WRKSRCTOP}/README ${PREFIX}/share/doc/tavrasm/README
	${INSTALL_PROGRAM} ${WRKSRC}/tavrasm ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
