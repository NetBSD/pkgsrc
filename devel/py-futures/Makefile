# $NetBSD: Makefile,v 1.10 2019/11/03 10:18:27 rillig Exp $

DISTNAME=	futures-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/futures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/pythonfutures
COMMENT=	Library brings asynchronous computations from Python 3.x
LICENSE=	python-software-foundation

PYTHON_VERSIONS_ACCEPTED=	27 # included in 3+

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
