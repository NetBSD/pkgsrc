# $NetBSD: Makefile,v 1.3 2003/06/26 13:48:55 seb Exp $
#

DISTNAME=	openal-20030125
PKGREVISION=	1
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

USE_NEW_TEXINFO=	YES
USE_MAKEINFO=	YES
INFO_FILES=	openal.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
