# $NetBSD: Makefile,v 1.10 2024/06/05 22:44:57 wiz Exp $

DISTNAME=	sortedcontainers-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sortedcontainers/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.grantjenks.com/docs/sortedcontainers/
COMMENT=	Sorted collections library written in pure-Python
LICENSE=	apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

PYTHON_27_ACCEPTED=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
