# $NetBSD: Makefile,v 1.1 2021/07/18 18:06:39 gutteridge Exp $

DISTNAME=	scour-0.38.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scour/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/scour-project/scour
COMMENT=	Scour SVG Optimizer
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
