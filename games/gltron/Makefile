# $NetBSD: Makefile,v 1.23 2008/04/22 21:25:18 wiz Exp $
#

DISTNAME=	gltron-0.70-source
PKGNAME=	${DISTNAME:S/-source$//}
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gltron/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://gltron.sourceforge.net/
COMMENT=	3D lightcycle game inspired by the movie Tron

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --disable-warn

LIBS.SunOS+=	-lm

.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
