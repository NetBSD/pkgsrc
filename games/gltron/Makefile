# $NetBSD: Makefile,v 1.3 2003/04/11 00:34:49 salo Exp $
#

DISTNAME=	gltron-0.62-source
PKGNAME=	${DISTNAME:S/-source$//}
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gltron/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://gltron.sourceforge.net/
COMMENT=	3D lightcycle game inspired by the movie Tron

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

.include "../../audio/SDL_sound/buildlink2.mk"
.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
