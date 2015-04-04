# $NetBSD: Makefile,v 1.4 2015/04/04 21:50:51 rodent Exp $

DISTNAME=	bcrypt-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	https://pypi.python.org/packages/source/b/bcrypt/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/pyca/bcrypt/
COMMENT=	Modern password hashing for your software and your servers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
