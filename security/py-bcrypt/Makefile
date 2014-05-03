# $NetBSD: Makefile,v 1.1 2014/05/03 02:27:10 rodent Exp $

DISTNAME=	bcrypt-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	https://pypi.python.org/packages/source/b/bcrypt/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/dstufft/bcrypt/
COMMENT=	Modern password hashing for your software and your servers
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
