# $NetBSD: Makefile,v 1.3 2017/10/31 08:27:55 adam Exp $

DISTNAME=	requests_ntlm-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests_ntlm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-ntlm
COMMENT=	NTLM authentication handler for python-requests
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-ntlm-auth>=1.0.2:../../security/py-ntlm-auth
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
