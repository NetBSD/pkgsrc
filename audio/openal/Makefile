# $NetBSD: Makefile,v 1.1.1.1 2003/03/17 15:57:04 jmmv Exp $
#

DISTNAME=	openal-20030125
WRKSRC=		${WRKDIR}/${DISTNAME}fbsd/linux
CATEGORIES=	audio
MASTER_SITES=	http://math.smsu.edu/~erik/files/fbsd/ \
		http://www.smluc.org/~erik/ \
		http://csc.smsu.edu/~greenwald/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	3D positional spatialized sound library

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES

INFO_FILES=	openal.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
