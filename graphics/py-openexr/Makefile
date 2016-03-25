# $NetBSD: Makefile,v 1.2 2016/03/25 21:12:33 joerg Exp $

DISTNAME=	OpenEXR-1.2.0
PKGNAME=	${PYPKGPREFIX}-openexr-1.2.0
CATEGORIES=	graphics python
MASTER_SITES=	http://excamera.com/files/

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

PYTHON_VERSIONS_ACCEPTED=		27

.include "../../graphics/openexr/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
