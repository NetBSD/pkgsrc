# $NetBSD: Makefile,v 1.44 2016/07/09 13:03:46 wiz Exp $

DISTNAME=	hatari-1.9.0
CATEGORIES=	emulators
MASTER_SITES=	http://download.tuxfamily.org/hatari/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hatari.tuxfamily.org/
COMMENT=	Atari ST emulator
LICENSE=	gnu-gpl-v2

USE_CMAKE=		yes
USE_LANGUAGES=		c
CMAKE_ARGS+=		-DENABLE_OSX_BUNDLE:BOOL=0

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 1.7.0
REPLACE_PYTHON+=	python-ui/config.py
REPLACE_PYTHON+=	python-ui/debugui.py
REPLACE_PYTHON+=	python-ui/dialogs.py
REPLACE_PYTHON+=	python-ui/gentypes.py
REPLACE_PYTHON+=	python-ui/hatari.py
REPLACE_PYTHON+=	python-ui/hatariui.py
REPLACE_PYTHON+=	python-ui/tests/pygtk-hello-world.py
REPLACE_PYTHON+=	python-ui/uihelpers.py
REPLACE_PYTHON+=	tests/tosboot/tos_tester.py
REPLACE_PYTHON+=	tools/atari-convert-dir.py
REPLACE_PYTHON+=	tools/atari-hd-image.sh
REPLACE_PYTHON+=	tools/debugger/hatari_profile.py
REPLACE_PYTHON+=	tools/debugger/hatari_spinloop.py
REPLACE_PYTHON+=	tools/hconsole/example.py
REPLACE_PYTHON+=	tools/hconsole/hconsole.py

INSTALLATION_DIRS+=	share/doc/hatari

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
