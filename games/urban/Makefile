# $NetBSD: Makefile,v 1.24 2024/05/06 08:40:26 jperkin Exp $
#

DISTNAME=	urban-1.5.3
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://urban.bengburken.net/files/linux/
DISTFILES=	urban-1.5.3${EXTRACT_SUFX} sound${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://urban.bengburken.net/eng/
COMMENT=	U.R.B.A.N The Cyborg Project

PTHREAD_AUTO_VARS=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/urban

post-install:
	cd ${WRKDIR} && pax -rwppm snd ${DESTDIR}${PREFIX}/share/urban

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
