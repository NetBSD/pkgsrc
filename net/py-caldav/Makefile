# $NetBSD: Makefile,v 1.2 2014/02/02 00:58:06 rodent Exp $

DISTNAME=	caldav-0.1.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	https://pypi.python.org/packages/source/c/caldav/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://bitbucket.org/cyrilrbt/caldav
COMMENT=	CalDAV (RFC4791) client library for Python
LICENSE=	apache-2.0 AND gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	caldav/__init__.py caldav/davclient.py
REPLACE_PYTHON+=	caldav/elements/__init__.py caldav/elements/base.py
REPLACE_PYTHON+=	caldav/elements/cdav.py caldav/elements/dav.py
REPLACE_PYTHON+=	caldav/lib/error.py caldav/lib/namespace.py
REPLACE_PYTHON+=	caldav/lib/url.py caldav/lib/vcal.py caldav/objects.py
REPLACE_PYTHON+=	tests/conf.py tests/proxy.py tests/test_caldav.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
