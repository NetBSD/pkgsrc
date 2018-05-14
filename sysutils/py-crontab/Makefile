# $NetBSD: Makefile,v 1.9 2018/05/14 08:12:54 adam Exp $

DISTNAME=	python-crontab-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-crontab/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/doctormo/python-crontab
COMMENT=	Python Crontab API
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil>=0.10:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
