# $NetBSD: Makefile,v 1.25.14.1 2016/05/11 15:35:39 bsiegert Exp $
#

DISTNAME=		Wormz-1.0b5
PKGNAME=		wormz-1.0b5
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		http://lide.punknet.cz/miri/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lide.punknet.cz/miri/Wormz.html
COMMENT=		Networked game for X11
LICENSE=		gnu-gpl-v2

# NetBSD/UDPConnection.o: file not recognized: File truncated
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/Wormz
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

post-extract:
	${MKDIR} ${WRKSRC}/${OPSYS}
	${TOUCH} ${WRKSRC}/${OPSYS}/.depend

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} depend

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
