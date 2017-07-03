# $NetBSD: Makefile,v 1.3 2017/07/03 13:48:20 adam Exp $

DISTNAME=	python-crontab-2.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-crontab/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/doctormo/python-crontab
COMMENT=	Python Crontab API
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-dateutil>=0.10:../../time/py-dateutil

USE_LANGUAGES=		# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
