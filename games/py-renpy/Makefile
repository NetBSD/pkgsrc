# $NetBSD: Makefile,v 1.2 2013/10/24 12:43:52 ryoon Exp $

DISTNAME=	renpy-6.15.7-source
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-source//}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.renpy.org/dl/6.15.7/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.renpy.org/dl/6.15.7/
COMMENT=	Visual Novel Engine written in Python
LICENSE=	mit

USE_TOOLS+=	pax

PYDISTUTILSPKG=	yes
PYSETUPSUBDIR=	module

MAKE_ENV+=	RENPY_DEPS_INSTALL=${BUILDLINK_PREFIX.SDL}::${BUILDLINK_PREFIX.freetype2}::${BUILDLINK_PREFIX.zlib}

INSTALLATION_DIRS=	bin

REPLACE_PYTHON=		renpy.py

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
.include "../../devel/py-game/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../multimedia/ffmpeg010/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
