# $NetBSD: Makefile,v 1.7 2025/04/15 05:04:21 adam Exp $

DISTNAME=	OctoPrint-PiSupport-2023.10.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint-PiSupport/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-PiSupport
COMMENT=	OctoPrint plugin providing information about your Pi in the UI
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
