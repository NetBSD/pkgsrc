# $NetBSD: Makefile,v 1.7 2018/10/18 10:17:25 adam Exp $

DISTNAME=	autopep8-1.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autopep8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hhatto/autopep8
COMMENT=	Automatic formatter of Python code to conform to PEP 8
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.3:../../devel/py-codestyle

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} autopep8 autopep8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
