# $NetBSD: Makefile,v 1.15 2006/10/28 21:29:47 wiz Exp $
#

DISTNAME=	src-mdp-1.9a5
PKGREVISION=	1
CATEGORIES=	mbone
MASTER_SITES+=	http://downloads.pf.itd.nrl.navy.mil/mdp/
MASTER_SITES+=	http://downloads.pf.itd.nrl.navy.mil/protolib/
DISTFILES=	src-mdp-1.9a5.tgz src-protolib-1.0a3d.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://cs.itd.nrl.navy.mil/work/mdp/
COMMENT=	Multicast file transfer

WRKSRC=		${WRKDIR}/mdp/unix
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake
BUILD_TARGET=	mdp

INSTALLATION_DIRS=	bin

pre-build:
		${LN} -sf ${WRKSRC}/Makefile.netbsd ${WRKSRC}/Makefile
		${RM} -f ${WRKSRC}/../protolib
		${LN} -sf ${WRKDIR}/protolib-1.0 ${WRKSRC}/../protolib
do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/mdp ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
