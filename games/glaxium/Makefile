# $NetBSD: Makefile,v 1.14 2006/06/12 16:28:09 wiz Exp $
#

DISTNAME=	glaxium_0.5
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://xhosxe.free.fr/glaxium/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xhosxe.free.fr/glaxium/
COMMENT=	Space-ship OpenGL shoot them up

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

BUILD_TARGET=		glaxium

SUBST_CLASSES+=		bill
SUBST_STAGE.bill=	post-configure
SUBST_FILES.bill=	conf.h
SUBST_SED.bill=		-e "s,share\/games,share,g"
SUBST_MESSAGE.bill=	Fixing data path.

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
