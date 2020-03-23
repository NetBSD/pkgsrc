# $NetBSD: Makefile,v 1.2 2020/03/23 09:41:00 jperkin Exp $

DISTNAME=	beancount-2.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beancount/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://furius.ca/beancount/
COMMENT=	Command-line double-entry bookkeeping
LICENSE=	gnu-gpl-v2

# Manually transcribed from requirements.txt.
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.6.0:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-bottle>=0.12:../../www/py-bottle
DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.0:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=1.6.0:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=4.0:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.10:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-magic>=0.4.12:../../sysutils/py-magic

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-google-api-python-client

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
