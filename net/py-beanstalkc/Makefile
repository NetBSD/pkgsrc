# $NetBSD: Makefile,v 1.2 2015/12/05 21:25:53 adam Exp $

DISTNAME=	beanstalkc-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/b/beanstalkc/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/earl/beanstalkc
COMMENT=	Simple beanstalkd client library for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

REPLACE_PYTHON+=		beanstalkc.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
