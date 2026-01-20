# $NetBSD: Makefile,v 1.7 2026/01/20 16:06:25 gdt Exp $

DISTNAME=	beancount-2.3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/beancount/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://furius.ca/beancount/
COMMENT=	Command-line double-entry bookkeeping
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-bottle-[0-9]*:../../www/py-bottle
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client-[0-9]*:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-magic-[0-9]*:../../sysutils/py-magic
DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
