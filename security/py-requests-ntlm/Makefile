# $NetBSD: Makefile,v 1.7 2022/10/19 13:56:33 nia Exp $

DISTNAME=	requests_ntlm-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	security www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests_ntlm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-ntlm
COMMENT=	NTLM authentication handler for python-requests
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-ntlm-auth>=1.0.2:../../security/py-ntlm-auth
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
