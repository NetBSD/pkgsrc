# $NetBSD: Makefile,v 1.2 2004/04/17 14:27:01 xtraeme Exp $
#

DISTNAME=	${DISTFILES}
PKGNAME=	urban-1.5.2
CATEGORIES=	games
MASTER_SITES=	http://urban.worldonline.nl/files/linux/
DISTFILES=	urban-1.5.2${EXTRACT_SUFX} sound${EXTRACT_SUFX}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://urban.worldonline.nl/
COMMENT=	U.R.B.A.N The Cyborg Project

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME}

post-install:
	cd ${WRKDIR} && ${PAX} -rwppm snd ${PREFIX}/share/urban

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
