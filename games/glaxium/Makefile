# $NetBSD: Makefile,v 1.30 2023/05/31 21:53:00 wiz Exp $
#

DISTNAME=	glaxium_0.5
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	15
CATEGORIES=	games
MASTER_SITES=	http://xhosxe.free.fr/glaxium/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xhosxe.free.fr/glaxium/
COMMENT=	Space-ship OpenGL shoot them up

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++
CONFIGURE_ENV+=		X11_LDFLAGS=${X_LDFLAGS:Q}
# uses cos()
X_LDFLAGS=		${X11_LDFLAGS} -lm

BUILD_TARGET=		glaxium

SUBST_CLASSES+=		bill
SUBST_STAGE.bill=	post-configure
SUBST_FILES.bill=	conf.h
SUBST_SED.bill=		-e "s,share\/games,share,g"
SUBST_MESSAGE.bill=	Fixing data path.

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man6 \
			share/glaxium/samples share/glaxium/textures

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glaxium ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/glaxium.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/
	${INSTALL_DATA} ${WRKSRC}/samples/*.wav \
		${DESTDIR}${PREFIX}/share/glaxium/samples/
	${INSTALL_DATA} ${WRKSRC}/samples/*.xm \
		${DESTDIR}${PREFIX}/share/glaxium/samples/
	${INSTALL_DATA} ${WRKSRC}/textures/*.png \
		${DESTDIR}${PREFIX}/share/glaxium/textures/

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
