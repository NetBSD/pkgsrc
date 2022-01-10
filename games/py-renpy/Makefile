# $NetBSD: Makefile,v 1.27 2022/01/10 21:34:30 wiz Exp $

DISTNAME=	renpy-6.18.3-source
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-source//}
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	https://www.renpy.org/dl/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.renpy.org/
COMMENT=	Visual Novel Engine written in Python
LICENSE=	mit

USE_TOOLS+=	pax
PYSETUPSUBDIR=	module
EGG_NAME=	Ren_Py-${PKGVERSION_NOREV}.761

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported

RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.SDL}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.freetype2}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.zlib}
RENPY_DEPS_INSTALL+=	${BUILDLINK_PREFIX.ffmpeg2}/${BUILDLINK_LIBDIRS.ffmpeg2}

MAKE_ENV+=	RENPY_DEPS_INSTALL=${RENPY_DEPS_INSTALL:ts;:S,;,::,g:Q}
MAKE_ENV+=	RENPY_CYTHON=cython-${PYVERSSUFFIX}

INSTALLATION_DIRS=	bin ${RENPY_DIR}

REPLACE_PYTHON=		renpy.py launcher/game/tkaskdir.py

RENPY_DIR=		share/renpy

pre-configure:
	cd ${WRKSRC} && find . -name '*.py[co]' -print -delete

post-install:
	cd ${WRKSRC}; ${FIND} doc launcher renpy template the_question \
		tutorial update \
		-type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/${RENPY_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/renpy.py ${DESTDIR}${PREFIX}/${RENPY_DIR}
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -fs ../${RENPY_DIR}/renpy.py .

.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/py-game/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
