# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:07 wiz Exp $

DISTNAME=	v0.58
PKGNAME=	${PYPKGPREFIX}-gdmodule-${DISTNAME:S/v//}
CATEGORIES=	graphics python
MASTER_SITES=	https://github.com/Solomoriah/gdmodule/archive/

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://github.com/Solomoriah/gdmodule
COMMENT=	Python interface to gd graphics library
LICENSE=	original-bsd

DIST_SUBDIR=	py-gdmodule
WRKSRC=		${WRKDIR}/gdmodule-${DISTNAME:S/v//}

EGG_NAME=	gdmodule-${DISTNAME:S/v//}

PYSETUP=	Setup.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.58

BUILDLINK_API_DEPENDS.gd+=	gd>=2.0.23
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
