# $NetBSD: Makefile,v 1.1 2013/08/05 17:42:19 kleink Exp $

DISTNAME=	passlib-1.6.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://passlib.googlecode.com/files/ \
		http://pypi.python.org/packages/source/p/passlib/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://passlib.googlecode.com/
COMMENT=	Comprehensive password hashing framework supporting over 30 schemes
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
