# $NetBSD: Makefile,v 1.4 2003/05/02 11:54:56 wiz Exp $
#

DISTNAME=	gltron-0.62-source
PKGNAME=	${DISTNAME:S/-source$//}
PKGREVISION=	1
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
