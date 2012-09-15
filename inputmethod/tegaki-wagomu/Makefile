# $NetBSD: Makefile,v 1.8 2012/09/15 10:05:17 obache Exp $
#

DISTNAME=	tegaki-wagomu-0.3.1
PKGREVISION=	5
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.tegaki.org/releases/${PKGVERSION_NOREV}/ \
		http://www.tegaki.org/releases/0.3/
DISTFILES=	tegaki-wagomu-0.3${EXTRACT_SUFX} ${DEFAULT_DISTFILES}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Simple handwriting recognition engine based on DTW
LICENSE=	gnu-gpl-v2

DEPENDS+=	tegaki-python>=0.3:../../inputmethod/tegaki-python
DEPENDS+=	swig-[0-9]*:../../devel/swig

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# some files are missing in distfile, taken from 0.3.
post-extract:
		${CP} ${WRKDIR}/tegaki-wagomu-0.3/tegakiwagomu.py ${WRKSRC}
		${CP} ${WRKDIR}/tegaki-wagomu-0.3/wagomu.h ${WRKSRC}

SUBST_CLASSES+=		fixver
SUBST_STAGE.fixver=	pre-configure
SUBST_FILES.fixver=	tegakiwagomu.py
SUBST_SED.fixver=	-e 's|0\.3|${PKGVERSION_NOREV}|'

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
