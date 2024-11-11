# $NetBSD: Makefile,v 1.5 2024/11/11 07:28:53 wiz Exp $

DISTNAME=	OctoPrint-PiSupport-2023.10.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=O/OctoPrint-PiSupport/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-PiSupport
COMMENT=	OctoPrint plugin providing information about your Pi in the UI
LICENSE=	gnu-agpl-v3

WHEEL_NAME=	${DISTNAME:S/-/_/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
