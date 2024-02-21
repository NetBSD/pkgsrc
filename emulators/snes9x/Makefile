# $NetBSD: Makefile,v 1.61 2024/02/21 11:31:21 nia Exp $

.include "../../emulators/snes9x/Makefile.common"

MAINTAINER=	nia@NetBSD.org
COMMENT=	Super Nintendo Entertainment System (SNES) emulator (CLI version)

FORCE_CXX_STD=		c++11

CONFIGURE_DIRS=		unix
BUILD_DIRS=		unix

GNU_CONFIGURE=		yes

USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--enable-netplay

CONFIGURE_ARGS+=	--with-system-zip

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

.include "options.mk"
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
