# $NetBSD: Makefile,v 1.9 2025/04/15 05:04:21 adam Exp $

DISTNAME=	OctoPrint-FileCheck-2024.11.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint-FileCheck/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FileCheck
COMMENT=	Checks for common issues in uploaded files
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
