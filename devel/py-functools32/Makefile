# $NetBSD: Makefile,v 1.1 2017/06/05 07:27:02 adam Exp $

DISTNAME=	functools32-3.2.3-2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:C/-([0-9])$/.\1/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/functools32/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MiCHiLU/python-functools32
COMMENT=	Backport of the functools module from Python 3.2.3
LICENSE=	python-software-foundation

USE_LANGUAGES=		# none

PYTHON_VERSIONS_ACCEPTED=	27

EGG_NAME=	${DISTNAME:C/-([0-9])$/_\1/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
