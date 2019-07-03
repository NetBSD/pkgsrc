# $NetBSD: Makefile,v 1.48 2019/07/03 09:06:37 nia Exp $

DISTNAME=	dosbox-0.74-3
PKGNAME=	dosbox-0.74.3
PKGREVISION=	1
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

SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	pre-configure
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

# dynamic recompiler enabled by default
NOT_PAX_MPROTECT_SAFE+=	bin/dosbox

ICON_SIZES=	256 48 32 24 16
ICON_DIR=	share/icons/hicolor

TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/dosbox
.for size in ${ICON_SIZES}
INSTALLATION_DIRS+=	${ICON_DIR}/${size}x${size}/apps
.endfor

post-extract:
	convert ${WRKSRC}/src/dosbox.ico[0] ${WRKDIR}/dosbox-256.png
	convert ${WRKSRC}/src/dosbox.ico[1] ${WRKDIR}/dosbox-48.png
	convert ${WRKSRC}/src/dosbox.ico[2] ${WRKDIR}/dosbox-32.png
	convert ${WRKSRC}/src/dosbox.ico[3] ${WRKDIR}/dosbox-24.png
	convert ${WRKSRC}/src/dosbox.ico[4] ${WRKDIR}/dosbox-16.png

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${FILESDIR}/dosbox.desktop ${DESTDIR}${PREFIX}/share/applications
.for size in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKDIR}/dosbox-${size}.png \
	    ${DESTDIR}${PREFIX}/${ICON_DIR}/${size}x${size}/apps/dosbox.png
.endfor

.include "options.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
