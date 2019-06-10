# $NetBSD: Makefile,v 1.46 2019/06/10 12:41:23 nia Exp $

DISTNAME=	dosbox-0.74-2
PKGNAME=	dosbox-0.74.2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dosbox.com/
COMMENT=	Multi-platform DOS emulator using SDL
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-dynrec
CPPFLAGS.SunOS+=	-DDISABLE_JOYSTICK
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mclang*)
CPPFLAGS+=		-fPIC
.endif
LDFLAGS.SunOS+=		-lsocket
INSTALLATION_DIRS=	share/doc/dosbox

SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	pre-configure
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

# dynamic recompiler enabled by default
NOT_PAX_MPROTECT_SAFE+=	bin/dosbox

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dosbox

.include "options.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
