# $NetBSD: Makefile,v 1.4 2022/02/07 21:07:36 adam Exp $

DISTNAME=	click-didyoumean-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-didyoumean/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timofurrer/click-didyoumean
COMMENT=	Enable git-like did-you-mean feature in click
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-click>=7:../../devel/py-click

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
