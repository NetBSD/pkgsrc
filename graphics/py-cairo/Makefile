# $NetBSD: Makefile,v 1.59 2018/11/14 22:21:45 kleink Exp $

DISTNAME=		pycairo-1.17.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		1
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
