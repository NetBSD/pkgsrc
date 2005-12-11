# $NetBSD: Makefile,v 1.18 2005/12/11 09:40:41 wiz Exp $
#

DISTNAME=	gltron-0.70-source
PKGNAME=	${DISTNAME:S/-source$//}
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gltron/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://gltron.sourceforge.net/
COMMENT=	3D lightcycle game inspired by the movie Tron

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --disable-warn

LIBS.SunOS+=	-lm

.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
