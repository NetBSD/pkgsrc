# $NetBSD: Makefile,v 1.41 2015/04/25 14:20:46 tnn Exp $

DISTNAME=	hatari-1.8.0
PKGREVISION=	1
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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.7.0
REPLACE_PYTHON+=	python-ui/config.py
REPLACE_PYTHON+=	python-ui/debugui.py
REPLACE_PYTHON+=	python-ui/dialogs.py
REPLACE_PYTHON+=	python-ui/hatari.py
REPLACE_PYTHON+=	python-ui/hatariui.py
REPLACE_PYTHON+=	python-ui/uihelpers.py

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing python
SUBST_FILES.fix-python+=	tools/hconsole/example.py
SUBST_FILES.fix-python+=	tools/debugger/hatari_profile.py
SUBST_FILES.fix-python+=	tools/hconsole/hconsole.py
SUBST_FILES.fix-python+=	python-ui/gentypes.py
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'

INSTALLATION_DIRS+=	share/doc/hatari

.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
