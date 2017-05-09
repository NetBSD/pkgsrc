# $NetBSD: Makefile,v 1.34 2017/05/09 08:06:54 adam Exp $

DISTNAME=	Pillow-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pillow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://python-pillow.org/
COMMENT=	Python Imaging Library (Fork)
LICENSE=	hpnd

USE_TOOLS+=	pkg-config

CONFLICTS+=	${PYPKGPREFIX}-imaging-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-olefile-*:../../devel/py-olefile

# XXX: (automatically) testing Pillow fails because it is builded on a
# separate directory (build/lib.*/PIL/). Manually cp(1) all the files to PIL/
# fixes that (but implementing a similar distutils.cmd logic here can easily
# leads to a buggy one). Disable the test for now.
#do-test:
#	${RUN}cd ${WRKSRC};${PKGSRC_SETENV} ${TEST_ENV} ${PYTHONBIN} selftest.py

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
