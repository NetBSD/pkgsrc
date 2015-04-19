# $NetBSD: Makefile,v 1.1 2015/04/19 00:47:58 rodent Exp $

DISTNAME=	py-bcrypt-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	https://pypi.python.org/packages/source/p/py-bcrypt/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://code.google.com/p/py-bcrypt
COMMENT=	Provides bcrypt password hashing and key derivation in python
LICENSE=	isc AND modified-bsd AND original-bsd

CONFLICTS+=	${PYPKGPREFIX}-bcrypt-[0-9]*:../../security/py-bcrypt

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
