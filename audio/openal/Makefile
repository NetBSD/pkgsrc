# $NetBSD: Makefile,v 1.2 2003/05/02 11:53:44 wiz Exp $
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

INFO_FILES=	openal.info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
