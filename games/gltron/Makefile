# $NetBSD: Makefile,v 1.7 2003/12/08 14:41:39 wiz Exp $
#

DISTNAME=	gltron-0.62-source
PKGBASE=	${DISTNAME:S/-source$//}
PKGNAME=	${PKGBASE}
PKGREVISION=	3
WRKSRC=		${WRKDIR}/${PKGBASE}
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
