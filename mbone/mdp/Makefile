# $NetBSD: Makefile,v 1.4 2003/10/11 03:20:30 grant Exp $
#

DISTNAME=	src-mdp-1.9a5
WRKSRC=		${WRKDIR}/mdp/unix
CATEGORIES=	mbone
MASTER_SITES+=	http://manimac.itd.nrl.navy.mil/MDP/dist/
MASTER_SITES+=	http://downloads.pf.itd.nrl.navy.mil/protolib/
DISTFILES=	src-mdp-1.9a5.tgz src-protolib-1.0a3d.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://manimac.itd.nrl.navy.mil/MDP/
COMMENT=	Multicast file transfer

USE_GMAKE=	YES
ALL_TARGET=	mdp

pre-build:
		${LN} -sf ${WRKSRC}/Makefile.netbsd ${WRKSRC}/Makefile
		${RM} -f ${WRKSRC}/../protolib
		${LN} -sf ${WRKDIR}/protolib-1.0 ${WRKSRC}/../protolib
do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/mdp ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
