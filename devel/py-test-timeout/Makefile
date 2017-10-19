# $NetBSD: Makefile,v 1.1 2017/10/19 06:52:03 adam Exp $

DISTNAME=	pytest-timeout-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-timeout/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/pytest-dev/pytest-timeout/
COMMENT=	Py.test plugin to abort hanging tests
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=2.8.0:../../devel/py-test

USE_LANGUAGES=	# none

#post-install:
#	cd ${DESTDIR}${PREFIX}/bin && \
#		${MV} py.test py.test-${PYVERSSUFFIX} && \
#		${MV} pytest pytest-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
