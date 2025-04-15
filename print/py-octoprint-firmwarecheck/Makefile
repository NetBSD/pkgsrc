# $NetBSD: Makefile,v 1.8 2025/04/15 05:04:21 adam Exp $

DISTNAME=	OctoPrint-FirmwareCheck-2021.10.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint-FirmwareCheck/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FirmwareCheck
COMMENT=	Checks for unsafe or broken printer firmwares
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl:S/-/_/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
