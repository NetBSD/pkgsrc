# $NetBSD: Makefile,v 1.4 2018/10/07 08:35:38 adam Exp $

DISTNAME=	sortedcontainers-2.0.5
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
