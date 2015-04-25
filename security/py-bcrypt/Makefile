# $NetBSD: Makefile,v 1.7 2015/04/25 13:48:50 wiz Exp $

DISTNAME=	bcrypt-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	python security
MASTER_SITES=	https://pypi.python.org/packages/source/b/bcrypt/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/pyca/bcrypt/
COMMENT=	Modern password hashing for your software and your servers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

CONFLICTS+=	${PYPKGPREFIX}-py-bcrypt-[0-9]*

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
