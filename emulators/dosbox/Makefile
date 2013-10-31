# $NetBSD: Makefile,v 1.37 2013/10/31 15:10:49 wiz Exp $

DISTNAME=	dosbox-0.74
PKGREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dosbox.sourceforge.net/
COMMENT=	Multi-platform DOS emulator using SDL
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CPPFLAGS.SunOS+=	-DDISABLE_JOYSTICK
CPPFLAGS+=		-fPIC
LDFLAGS.SunOS+=		-lsocket
INSTALLATION_DIRS=	share/doc/dosbox

SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	post-patch
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dosbox

.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
