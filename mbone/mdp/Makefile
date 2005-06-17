# $NetBSD: Makefile,v 1.11 2005/06/17 03:50:20 jlam Exp $
#

DISTNAME=	src-mdp-1.9a5
CATEGORIES=	mbone
MASTER_SITES+=	http://manimac.itd.nrl.navy.mil/MDP/dist/
MASTER_SITES+=	http://downloads.pf.itd.nrl.navy.mil/protolib/
DISTFILES=	src-mdp-1.9a5.tgz src-protolib-1.0a3d.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://manimac.itd.nrl.navy.mil/MDP/
COMMENT=	Multicast file transfer

WRKSRC=		${WRKDIR}/mdp/unix
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
