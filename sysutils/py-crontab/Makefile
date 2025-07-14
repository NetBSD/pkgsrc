# $NetBSD: Makefile,v 1.29 2025/07/14 05:31:26 adam Exp $

DISTNAME=	python_crontab-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-crontab/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://gitlab.com/doctormo/python-crontab
COMMENT=	Python Crontab API
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
