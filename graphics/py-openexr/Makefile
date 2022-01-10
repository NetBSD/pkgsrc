# $NetBSD: Makefile,v 1.11 2022/01/10 21:49:42 wiz Exp $

DISTNAME=	OpenEXR-1.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OpenEXR/}

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://www.excamera.com/sphinx/articles-openexr.html
COMMENT=	Python module for ILM's OpenEXR image format and library
#LICENSE=	unknown

USE_LANGUAGES=	c c++

SUBST_CLASSES=		fix-path
SUBST_MESSAGE.fix-path=	Fixing paths.
SUBST_STAGE.fix-path=	pre-configure
SUBST_FILES.fix-path=	setup.py
SUBST_SED.fix-path=	-e 's,/usr/include/OpenEXR,${BUILDLINK_PREFIX.openexr}/include/OpenEXR,'
SUBST_SED.fix-path+=	-e 's,/usr/local/include/OpenEXR,${BUILDLINK_PREFIX.imath}/include/Imath,'
SUBST_SED.fix-path+=	-e 's,/usr/local/lib,${BUILDLINK_PREFIX.openexr}/lib,'
SUBST_SED.fix-path+=	-e 's,Half,OpenEXR,'
SUBST_SED.fix-path+=	-e 's,IlmImf,IlmThread,'

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
