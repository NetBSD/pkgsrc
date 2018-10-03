# $NetBSD: Makefile,v 1.5 2018/10/03 10:42:56 adam Exp $

DISTNAME=	OpenEXR-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OpenEXR/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://www.excamera.com/sphinx/articles-openexr.html
COMMENT=	Python module for ILM's OpenEXR image format and library
#LICENSE=	unknown

USE_LANGUAGES=	c c++

SUBST_CLASSES=		fix-path
SUBST_MESSAGE.fix-path=	Fixing paths.
SUBST_STAGE.fix-path=	pre-configure
SUBST_FILES.fix-path=	setup.py
SUBST_SED.fix-path=	-e 's,/usr/include/OpenEXR,${BUILDLINK_PREFIX.openexr}/include/OpenEXR,'
SUBST_SED.fix-path+=    -e 's,/usr/local/lib,${BUILDLINK_PREFIX.openexr}/lib,'

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
