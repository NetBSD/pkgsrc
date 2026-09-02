# $NetBSD: Makefile,v 1.50 2026/09/02 19:02:21 wiz Exp $

DISTNAME=	renpy-8.5.3-source
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-source//}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://www.renpy.org/dl/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.renpy.org/
COMMENT=	Visual Novel Engine written in Python
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

USE_LANGUAGES+=	gnu99 c++

DEPENDS+=	${PYPKGPREFIX}-future>=1.0.0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-pefile-[0-9]*:../../sysutils/py-pefile
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ecdsa-[0-9]*:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-rsa-[0-9]*:../../security/py-rsa

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} > 312
DEPENDS+=	${PYPKGPREFIX}-legacy-cgi-[0-9]*:../../www/py-legacy-cgi
.endif

USE_TOOLS+=	pax
EGG_NAME=	Ren_Py-${PKGVERSION_NOREV}.23091805

PYSETUPBUILDTARGET=	build_ext --inplace

PLIST_SUBST+=	PYTHON_VERSION=${PYTHON_VERSION}

MAKE_ENV+=	RENPY_CYTHON=cython-${PYVERSSUFFIX}

INSTALLATION_DIRS=	bin ${RENPY_DIR}

REPLACE_PYTHON=		renpy.py launcher/game/tkaskdir.py

RENPY_DIR=		share/renpy

UNAME_M!=		uname -m
RPYC_DIRS=		the_question tutorial launcher

pre-configure:
	cd ${WRKSRC} && find . -name '*.py[co]' -print -delete

post-install:
# For runtime permission denied errors.
.for m in ${RPYC_DIRS}
	cd ${WRKSRC} && \
		PYTHONPATH=build/lib.${LOWER_OPSYS}-${OS_VERSION}-${UNAME_M}-cpython-${PYTHON_VERSION} \
		${PYTHONBIN} ./renpy.py ${m} compile
.endfor
	cd ${WRKSRC}; \
		${FIND} doc gui launcher renpy sdk-fonts the_question \
			tutorial \
			-type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${RENPY_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/renpy.py ${DESTDIR}${PREFIX}/${RENPY_DIR}
	cd ${DESTDIR}${PREFIX}/bin && \
	${ECHO} '#!${SH}' > renpy && \
	${ECHO} '${PYTHONBIN} ${PREFIX}/${RENPY_DIR}/renpy.py "$$@"' >> renpy && \
	${CHMOD} 755 renpy

.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
# The following is not essential and not recommended.
#.include "../../devel/py-game_sdl2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/SDL2_gfx/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../multimedia/assimp/buildlink3.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
