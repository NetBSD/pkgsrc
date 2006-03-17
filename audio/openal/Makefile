# $NetBSD: Makefile,v 1.17 2006/03/17 22:39:02 jlam Exp $

DISTNAME=	openal-20040816
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://math.smsu.edu/~erik/files/fbsd/ \
		http://www.smluc.org/~erik/ \
		http://csc.smsu.edu/~greenwald/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openal.org/
COMMENT=	3D positional spatialized sound library

WRKSRC=			${WRKDIR}/${DISTNAME}/linux
USE_TOOLS+=		gmake makeinfo
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INFO_FILES=		openal.info
INSTALLATION_DIRS=	info

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/openal.info ${PREFIX}/info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
