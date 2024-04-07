# $NetBSD: Makefile,v 1.6 2024/04/07 07:34:19 wiz Exp $

DISTNAME=		pycairo-1.18.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		6
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=pygobject/}
GITHUB_PROJECT=		pycairo
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		leuzi@trash.net
HOMEPAGE=		https://cairographics.org/pycairo/
COMMENT=		Python bindings for cairo (Python 2.x version)
LICENSE=		gnu-lgpl-v2.1 OR mpl-1.1

USE_TOOLS+=		pkg-config

PYTHON_VERSIONS_ACCEPTED=	27

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
