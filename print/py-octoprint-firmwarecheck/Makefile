# $NetBSD: Makefile,v 1.6 2024/11/11 07:28:53 wiz Exp $

DISTNAME=	OctoPrint-FirmwareCheck-2021.10.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint-FirmwareCheck/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FirmwareCheck
COMMENT=	Checks for unsafe or broken printer firmwares
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
