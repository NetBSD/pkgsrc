# $NetBSD: Makefile,v 1.6 2003/09/16 12:16:50 adam Exp $
#

DISTNAME=	openal-20030724
WRKSRC=		${WRKDIR}/${DISTNAME}/linux
CATEGORIES=	audio
MASTER_SITES=	http://math.smsu.edu/~erik/files/fbsd/ \
		http://www.smluc.org/~erik/ \
		http://csc.smsu.edu/~greenwald/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	3D positional spatialized sound library

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

USE_MAKEINFO=	YES
INFO_FILES=	openal.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
