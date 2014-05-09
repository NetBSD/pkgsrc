# $NetBSD: Makefile,v 1.22 2014/05/09 07:37:13 wiz Exp $

.include "../../multimedia/ming/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		multimedia

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://www.libming.org/
COMMENT=		Python bindings for Ming library
LICENSE=		gnu-lgpl-v2.1

PY_PATCHPLIST=		yes
PYSETUPSUBDIR=		py_ext
EGG_NAME=		${DISTNAME:S/ming/mingc/}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.if defined(GIFLIB_IMPLEMENTATION) && ${GIFLIB_IMPLEMENTATION} != "libungif"
SUBST_CLASSES+=		giflib
SUBST_STAGE.giflib=	pre-configure
SUBST_FILES.giflib=	py_ext/setup.py
SUBST_SED.giflib=	-e 's/ungif/gif/g'
.endif
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
