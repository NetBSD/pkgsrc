# $NetBSD: Makefile,v 1.13 2025/04/22 20:14:38 wiz Exp $

DISTNAME=	pyxdg-0.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyxdg/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://freedesktop.org/wiki/Software/pyxdg
COMMENT=	Python library for XDG
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
