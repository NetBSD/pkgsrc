# $NetBSD: Makefile,v 1.9 2004/01/20 12:15:40 agc Exp $
#

DISTNAME=	gltron-0.70-source
PKGBASE=	${DISTNAME:S/-source$//}
PKGNAME=	${PKGBASE}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gltron/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://gltron.sourceforge.net/
COMMENT=	3D lightcycle game inspired by the movie Tron

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../audio/SDL_sound/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
