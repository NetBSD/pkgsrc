# $NetBSD: Makefile,v 1.29 2011/01/13 13:37:44 wiz Exp $
#

DISTNAME=	gltron-0.70-source
PKGNAME=	${DISTNAME:S/-source$//}
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gltron/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gltron.sourceforge.net/
COMMENT=	3D lightcycle game inspired by the movie Tron

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --disable-warn

LIBS.SunOS+=	-lm

.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
