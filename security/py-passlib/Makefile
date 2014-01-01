# $NetBSD: Makefile,v 1.2 2014/01/01 17:46:20 kleink Exp $

DISTNAME=	passlib-1.6.2
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
