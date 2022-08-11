# $NetBSD: Makefile,v 1.65 2022/08/11 05:08:19 gutteridge Exp $

DISTNAME=	hatari-2.3.1
PKGREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	https://download.tuxfamily.org/hatari/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hatari.tuxfamily.org/
COMMENT=	Atari ST emulator
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c99
CMAKE_ARGS+=		-DENABLE_OSX_BUNDLE=OFF
CMAKE_ARGS+=		-DMANDIR=${PKGMANDIR}/man1

REPLACE_PYTHON+=	python-ui/config.py
REPLACE_PYTHON+=	python-ui/debugui.py
REPLACE_PYTHON+=	python-ui/dialogs.py
REPLACE_PYTHON+=	python-ui/gentypes.py
REPLACE_PYTHON+=	python-ui/hatari.py
REPLACE_PYTHON+=	python-ui/hatariui.py
REPLACE_PYTHON+=	python-ui/uihelpers.py
REPLACE_PYTHON+=	tests/tosboot/tos_tester.py
REPLACE_PYTHON+=	tools/atari-convert-dir.py
REPLACE_PYTHON+=	tools/debugger/hatari_profile.py
REPLACE_PYTHON+=	tools/debugger/hatari_spinloop.py
REPLACE_PYTHON+=	tools/hconsole/example.py
REPLACE_PYTHON+=	tools/hconsole/hconsole.py

INSTALLATION_DIRS+=	share/doc/hatari

.include "../../mk/bsd.prefs.mk"

.include "../../audio/portaudio/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
