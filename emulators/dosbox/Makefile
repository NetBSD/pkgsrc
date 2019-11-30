# $NetBSD: Makefile,v 1.49 2019/11/30 11:16:17 nia Exp $

DISTNAME=	dosbox-0.74-3
PKGNAME=	dosbox-0.74.3
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dosbox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dosbox.com/
COMMENT=	Multi-platform DOS emulator using SDL
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-dynrec
CPPFLAGS.SunOS+=	-DDISABLE_JOYSTICK
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mclang*)
CPPFLAGS+=		-fPIC
.endif
LDFLAGS.SunOS+=		-lsocket

SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	pre-configure
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

# dynamic recompiler enabled by default
NOT_PAX_MPROTECT_SAFE+=	bin/dosbox

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/dosbox

post-extract:
	${PREFIX}/bin/icotool -x -i 1 ${WRKSRC}/src/dosbox.ico -o ${WRKDIR}/256.png
	${PREFIX}/bin/icotool -x -i 2 ${WRKSRC}/src/dosbox.ico -o ${WRKDIR}/48.png
	${PREFIX}/bin/icotool -x -i 3 ${WRKSRC}/src/dosbox.ico -o ${WRKDIR}/32.png
	${PREFIX}/bin/icotool -x -i 4 ${WRKSRC}/src/dosbox.ico -o ${WRKDIR}/24.png
	${PREFIX}/bin/icotool -x -i 5 ${WRKSRC}/src/dosbox.ico -o ${WRKDIR}/16.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${FILESDIR}/dosbox.desktop ${DESTDIR}${PREFIX}/share/applications
.for s in 256 48 32 24 16
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/dosbox.png
.endfor

.include "options.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
