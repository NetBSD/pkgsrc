# $NetBSD: Makefile,v 1.28 2025/04/14 07:36:11 adam Exp $

DISTNAME=	python_crontab-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-crontab/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://gitlab.com/doctormo/python-crontab
COMMENT=	Python Crontab API
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-dateutil>=0.10:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
