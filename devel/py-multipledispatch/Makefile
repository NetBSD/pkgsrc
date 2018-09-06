# $NetBSD: Makefile,v 1.5 2018/09/06 14:07:00 adam Exp $

DISTNAME=	multipledispatch-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/multipledispatch/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/mrocklin/multipledispatch
COMMENT=	Efficient, mostly complete implementation of multiple dispatch
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
