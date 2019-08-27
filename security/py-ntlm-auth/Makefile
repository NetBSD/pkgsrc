# $NetBSD: Makefile,v 1.6 2019/08/27 10:11:26 adam Exp $

DISTNAME=	ntlm-auth-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ntlm-auth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jborean93/ntlm-auth
COMMENT=	NTLM authentication handler for python-requests
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-cryptography-[0-9]*:../../security/py-cryptography

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
