# $NetBSD: Makefile,v 1.3 2012/10/06 14:25:15 asau Exp $
#

.include "../../inputmethod/zinnia/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES+=	python

COMMENT=	Zinnia python module

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PYSETUPSUBDIR=	python

EGG_NAME=	zinnia_python-0.0.0

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=${PKGVERSION_NOREV}
.include "../../inputmethod/zinnia/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
