# $NetBSD: Makefile,v 1.4 2017/04/18 15:39:19 fhajny Exp $

DISTNAME=	futures-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/futures/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/agronholm/pythonfutures
COMMENT=	Library brings asynchronous computations from Python 3.x
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # included in 3+

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
