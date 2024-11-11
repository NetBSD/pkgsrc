# $NetBSD: Makefile,v 1.25 2024/11/11 07:28:52 wiz Exp $

DISTNAME=	billiard-4.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/billiard/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/celery/billiard
COMMENT=	Python multiprocessing fork with improvements and bugfixes
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
