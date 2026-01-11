# $NetBSD: Makefile,v 1.9 2026/01/11 09:33:30 adam Exp $

DISTNAME=	octoprint_firmwarecheck-2025.7.23
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint-FirmwareCheck/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FirmwareCheck
COMMENT=	Checks for unsafe or broken printer firmwares
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
