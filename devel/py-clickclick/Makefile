# $NetBSD: Makefile,v 1.2 2017/07/09 10:35:56 adam Exp $

DISTNAME=	clickclick-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/clickclick/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zalando/python-clickclick
COMMENT=	Click utility functions
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click>=4.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
