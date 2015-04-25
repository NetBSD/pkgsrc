# $NetBSD: Makefile,v 1.24 2015/04/25 14:22:55 tnn Exp $
#

DISTNAME=	glaxium_0.5
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://xhosxe.free.fr/glaxium/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xhosxe.free.fr/glaxium/
COMMENT=	Space-ship OpenGL shoot them up

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
CONFIGURE_ENV+=		X11_LDFLAGS=${X_LDFLAGS:Q}

BUILD_TARGET=		glaxium

SUBST_CLASSES+=		bill
SUBST_STAGE.bill=	post-configure
SUBST_FILES.bill=	conf.h
SUBST_SED.bill=		-e "s,share\/games,share,g"
SUBST_MESSAGE.bill=	Fixing data path.

INSTALLATION_DIRS+=	bin
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			exec_prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "DragonFly" || ${OPSYS} == "SunOS"
X_LDFLAGS=	${X11_LDFLAGS} -lm -lstdc++
.else
X_LDFLAGS=	${X11_LDFLAGS}
.endif

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
