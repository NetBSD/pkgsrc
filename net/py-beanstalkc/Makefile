# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:37 wiz Exp $

DISTNAME=	beanstalkc-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beanstalkc/}

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
