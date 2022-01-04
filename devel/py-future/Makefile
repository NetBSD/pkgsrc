# $NetBSD: Makefile,v 1.7 2022/01/04 20:53:07 wiz Exp $

DISTNAME=	future-0.18.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
