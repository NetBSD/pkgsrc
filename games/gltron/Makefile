# $NetBSD: Makefile,v 1.11 2004/06/15 13:23:10 grant Exp $
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
USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

LIBS.SunOS+=	-lm

.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
