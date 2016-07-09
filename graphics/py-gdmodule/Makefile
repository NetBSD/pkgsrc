# $NetBSD: Makefile,v 1.7 2016/07/09 13:03:51 wiz Exp $

DISTNAME=	v0.58
PKGNAME=	${PYPKGPREFIX}-gdmodule-${DISTNAME:S/v//}
PKGREVISION=	2
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
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.58

BUILDLINK_API_DEPENDS.gd+=	gd>=2.0.23
.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
