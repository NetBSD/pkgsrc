# $NetBSD: Makefile,v 1.12 2011/11/01 06:02:14 sbd Exp $
#

.include "../../multimedia/ming/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		multimedia

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Python bindings for Ming library
LICENSE=		gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes

PYSETUPSUBDIR=		py_ext

PYDISTUTILSPKG=		yes

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
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
