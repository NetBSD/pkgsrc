# $NetBSD: Makefile,v 1.10 2004/05/07 01:14:46 xtraeme Exp $
#

DISTNAME=	openal-20030724
CATEGORIES=	audio
MASTER_SITES=	http://math.smsu.edu/~erik/files/fbsd/ \
		http://www.smluc.org/~erik/ \
		http://csc.smsu.edu/~greenwald/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	3D positional spatialized sound library

WRKSRC=		${WRKDIR}/${DISTNAME}/linux
GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make

USE_MAKEINFO=	YES
INFO_FILES=	openal.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
