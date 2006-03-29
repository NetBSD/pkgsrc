# $NetBSD: Makefile,v 1.13 2006/03/29 22:41:01 joerg Exp $
#

DISTNAME=	urban-1.5.3
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://urban.bengburken.net/files/linux/
DISTFILES=	urban-1.5.3${EXTRACT_SUFX} sound${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://urban.bengburken.net/eng/
COMMENT=	U.R.B.A.N The Cyborg Project

PTHREAD_AUTO_VARS=	yes
GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

post-install:
	cd ${WRKDIR} && ${PAX} -rwppm snd ${PREFIX}/share/urban

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
