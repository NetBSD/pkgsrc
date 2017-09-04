# $NetBSD: Makefile,v 1.2 2017/09/04 18:59:30 joerg Exp $

DISTNAME=	requests_ntlm-1.0.0
PKGNAME=	${PYPKGPREFIX}-requests-ntlm-1.0.0
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests_ntlm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/requests/requests-ntlm
COMMENT=	NTLM authentication handler for python-requests
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ntlm-auth-[0-9]*:../../security/py-ntlm-auth

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
