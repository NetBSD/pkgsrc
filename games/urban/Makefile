# $NetBSD: Makefile,v 1.12 2006/03/09 21:04:44 jlam Exp $
#

DISTNAME=	urban-1.5.3
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://urban.bengburken.net/files/linux/
DISTFILES=	urban-1.5.3${EXTRACT_SUFX} sound${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://urban.bengburken.net/eng/
COMMENT=	U.R.B.A.N The Cyborg Project

GNU_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

post-install:
	cd ${WRKDIR} && ${PAX} -rwppm snd ${PREFIX}/share/urban

.include "../../audio/libmikmod/buildlink3.mk"
.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
