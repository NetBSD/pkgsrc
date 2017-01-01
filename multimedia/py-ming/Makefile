# $NetBSD: Makefile,v 1.28 2017/01/01 14:43:48 wiz Exp $

.include "../../multimedia/ming/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		multimedia

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.libming.org/
COMMENT=		Python bindings for Ming library
LICENSE=		gnu-lgpl-v2.1

PY_PATCHPLIST=		yes
PYSETUPSUBDIR=		py_ext
EGG_NAME=		${DISTNAME:S/ming/mingc/}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

SUBST_CLASSES+=		giflib
SUBST_STAGE.giflib=	pre-configure
SUBST_FILES.giflib=	py_ext/setup.py
SUBST_SED.giflib=	-e 's/ungif/gif/g'

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
