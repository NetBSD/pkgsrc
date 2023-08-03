# $NetBSD: Makefile,v 1.9 2023/08/03 08:20:54 adam Exp $

DISTNAME=	requests-kerberos-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests-kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-kerberos
COMMENT=	Kerberos authentication handler for python-requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pyspnego-[0-9]*:../../security/py-pyspnego
DEPENDS+=	${PYPKGPREFIX}-requests>=1.1.0:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
