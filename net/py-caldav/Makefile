# $NetBSD: Makefile,v 1.15 2019/04/26 13:14:09 maya Exp $

DISTNAME=	caldav-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=c/caldav/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/cyrilrbt/caldav
COMMENT=	CalDAV (RFC4791) client library for Python
LICENSE=	apache-2.0 AND gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # as of 0.2.1

REPLACE_PYTHON+=	caldav/__init__.py caldav/davclient.py
REPLACE_PYTHON+=	caldav/elements/__init__.py caldav/elements/base.py
REPLACE_PYTHON+=	caldav/elements/cdav.py caldav/elements/dav.py
REPLACE_PYTHON+=	caldav/lib/error.py caldav/lib/namespace.py
REPLACE_PYTHON+=	caldav/lib/url.py caldav/lib/vcal.py caldav/objects.py
REPLACE_PYTHON+=	tests/conf.py tests/proxy.py tests/test_caldav.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
