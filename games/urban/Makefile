# $NetBSD: Makefile,v 1.7 2005/03/25 03:10:23 wiz Exp $
#

DISTNAME=	urban-1.5.3
CATEGORIES=	games
MASTER_SITES=	http://urban.bengburken.net/files/linux/
DISTFILES=	urban-1.5.3${EXTRACT_SUFX} sound${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://urban.bengburken.net/eng/
COMMENT=	U.R.B.A.N The Cyborg Project

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

post-install:
	cd ${WRKDIR} && ${PAX} -rwppm snd ${PREFIX}/share/urban

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
