# $NetBSD: Makefile,v 1.1 2017/09/04 18:57:20 joerg Exp $

DISTNAME=	ntlm-auth-1.0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=n/ntlm-auth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jborean93/ntlm-auth
COMMENT=	NTLM authentication handler for python-requests
LICENSE=	gnu-lgpl-v3

DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
