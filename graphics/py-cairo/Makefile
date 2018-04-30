# $NetBSD: Makefile,v 1.57 2018/04/30 06:11:55 wiz Exp $

DISTNAME=		pycairo-1.17.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_GITHUB:=pygobject/}
GITHUB_PROJECT=		pycairo
GITHUB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		leuzi@trash.net
HOMEPAGE=		http://cairographics.org/pycairo/
COMMENT=		Python bindings for cairo
LICENSE=		gnu-lgpl-v2.1 OR mpl-1.1

USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.13.1
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
