# $NetBSD: Makefile,v 1.1 2024/02/09 09:48:29 adam Exp $

DISTNAME=	cron_descriptor-1.4.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cron-descriptor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Salamek/cron-descriptor
COMMENT=	Converts cron expressions into human readable strings
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
