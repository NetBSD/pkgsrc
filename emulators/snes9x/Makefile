# $NetBSD: Makefile,v 1.59 2020/04/01 10:08:15 nia Exp $

PKGREVISION=	1

.include "../../emulators/snes9x/Makefile.common"

MAINTAINER=	nia@NetBSD.org
COMMENT=	Super Nintendo Entertainment System (SNES) emulator (CLI version)

CONFIGURE_DIRS=		unix
BUILD_DIRS=		unix

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-netplay

CONFIGURE_ARGS+=	--with-system-zip

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correct path to OSS device.
SUBST_FILES.oss+=	unix/unix.cpp
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"

CONFIGURE_ARGS+=	--enable-sound
.else
PKG_SKIP_REASON+=	"No sound support on this platform"
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/snes9x

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unix/snes9x \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/changes.txt \
	    ${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/docs/control-inputs.txt \
	    ${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/docs/controls.txt \
	    ${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/docs/porting.html \
	    ${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/docs/snapshots.txt \
	    ${DESTDIR}${PREFIX}/share/doc/snes9x
	${INSTALL_MAN} ${WRKSRC}/unix/docs/readme_unix.html \
	    ${DESTDIR}${PREFIX}/share/doc/snes9x

.include "../../archivers/minizip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
