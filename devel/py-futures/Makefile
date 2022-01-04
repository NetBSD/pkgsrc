# $NetBSD: Makefile,v 1.11 2022/01/04 20:53:07 wiz Exp $

DISTNAME=	futures-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
