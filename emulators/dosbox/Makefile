# $NetBSD: Makefile,v 1.19 2007/01/20 02:25:31 rillig Exp $

DISTNAME=	dosbox-0.65
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://dosbox.sourceforge.net/
COMMENT=	Multi-platform DOS emulator using SDL

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CPPFLAGS.SunOS+=	-DDISABLE_JOYSTICK
INSTALLATION_DIRS=	share/doc/dosbox

SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	post-patch
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dosbox

.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
