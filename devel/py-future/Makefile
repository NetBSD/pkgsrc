# $NetBSD: Makefile,v 1.5 2018/10/31 10:54:39 adam Exp $

DISTNAME=	future-0.17.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/future/}

MAINTAINER=	gde@llew.me
#HOMEPAGE=	https://python-future.org/
COMMENT=	Clean single-source support for Python 3 and 2
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} futurize futurize-${PYVERSSUFFIX} && \
		${MV} pasteurize pasteurize-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
