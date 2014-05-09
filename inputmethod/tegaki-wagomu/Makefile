# $NetBSD: Makefile,v 1.13 2014/05/09 07:37:09 wiz Exp $

DISTNAME=	tegaki-wagomu-0.3.1
PKGREVISION=	6
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/ \
		http://www.tegaki.org/releases/0.3/
DISTFILES=	tegaki-wagomu-0.3${EXTRACT_SUFX} ${DEFAULT_DISTFILES}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Simple handwriting recognition engine based on DTW
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.3:../../inputmethod/tegaki-python
BUILD_DEPENDS+=	swig-1.[0-9]*:../../devel/swig

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# some files are missing in distfile, taken from 0.3.
# http://sourceforge.net/p/tegaki/bugs/8/
post-extract:
		${CP} ${WRKDIR}/tegaki-wagomu-0.3/tegakiwagomu.py ${WRKSRC}
		${CP} ${WRKDIR}/tegaki-wagomu-0.3/wagomu.h ${WRKSRC}

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	tegakiwagomu.py
SUBST_SED.fixver=	-e 's|0\.3|${PKGVERSION_NOREV}|'

EGG_NAME=	${DISTNAME:S/-/_/}
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.3.1

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
