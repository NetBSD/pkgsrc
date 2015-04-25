# $NetBSD: Makefile,v 1.34 2015/04/25 14:20:39 tnn Exp $

DISTNAME=	pygame-1.9.1release
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/release//}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.pygame.org/ftp/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.pygame.org/
COMMENT=	Set of Python modules designed for writing games
LICENSE=	gnu-lgpl-v2.1

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-no-integrated-as
.endif

REPLACE_PYTHON+=	bundle_docs.py
REPLACE_PYTHON+=	config.py
REPLACE_PYTHON+=	examples/aacircle.py
REPLACE_PYTHON+=	examples/aliens.py
REPLACE_PYTHON+=	examples/arraydemo.py
REPLACE_PYTHON+=	examples/blend_fill.py
REPLACE_PYTHON+=	examples/blit_blends.py
REPLACE_PYTHON+=	examples/camera.py
REPLACE_PYTHON+=	examples/chimp.py
REPLACE_PYTHON+=	examples/cursors.py
REPLACE_PYTHON+=	examples/eventlist.py
REPLACE_PYTHON+=	examples/fastevents.py
REPLACE_PYTHON+=	examples/fonty.py
REPLACE_PYTHON+=	examples/glcube.py
REPLACE_PYTHON+=	examples/headless_no_windows_needed.py
REPLACE_PYTHON+=	examples/liquid.py
REPLACE_PYTHON+=	examples/macosx/aliens_app_example/aliens.py
REPLACE_PYTHON+=	examples/mask.py
REPLACE_PYTHON+=	examples/midi.py
REPLACE_PYTHON+=	examples/moveit.py
REPLACE_PYTHON+=	examples/movieplayer.py
REPLACE_PYTHON+=	examples/oldalien.py
REPLACE_PYTHON+=	examples/overlay.py
REPLACE_PYTHON+=	examples/pixelarray.py
REPLACE_PYTHON+=	examples/scaletest.py
REPLACE_PYTHON+=	examples/scrap_clipboard.py
REPLACE_PYTHON+=	examples/scroll.py
REPLACE_PYTHON+=	examples/sound.py
REPLACE_PYTHON+=	examples/sound_array_demos.py
REPLACE_PYTHON+=	examples/stars.py
REPLACE_PYTHON+=	examples/testsprite.py
REPLACE_PYTHON+=	examples/vgrade.py
REPLACE_PYTHON+=	makeref.py
REPLACE_PYTHON+=	msys_build_deps.py
REPLACE_PYTHON+=	msys_link_VC_2008_dlls.py
REPLACE_PYTHON+=	run_tests.py
REPLACE_PYTHON+=	setup.py
REPLACE_PYTHON+=	test/test_utils/unittest.py

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
