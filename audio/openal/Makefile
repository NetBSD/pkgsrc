# $NetBSD: Makefile,v 1.8 2004/01/22 07:15:00 grant Exp $
#

DISTNAME=	openal-20030724
CATEGORIES=	audio
MASTER_SITES=	http://math.smsu.edu/~erik/files/fbsd/ \
		http://www.smluc.org/~erik/ \
		http://csc.smsu.edu/~greenwald/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	3D positional spatialized sound library

WRKSRC=		${WRKDIR}/${DISTNAME}/linux
GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GNU_TOOLS+=	make

USE_MAKEINFO=	YES
INFO_FILES=	openal.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
