# $NetBSD: Makefile,v 1.23 2022/01/04 20:54:48 wiz Exp $

DISTNAME=	python-crontab-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-crontab/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://gitlab.com/doctormo/python-crontab
COMMENT=	Python Crontab API
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil>=0.10:../../time/py-dateutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
