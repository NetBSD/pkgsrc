# $NetBSD: Makefile,v 1.6 2020/06/08 06:55:20 adam Exp $

DISTNAME=	sortedcontainers-2.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sortedcontainers/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.grantjenks.com/docs/sortedcontainers/
COMMENT=	Sorted collections library written in pure-Python
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
