# $NetBSD: Makefile,v 1.27 2012/10/23 18:16:52 asau Exp $

DISTNAME=	pyOpenSSL-0.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyOpenSSL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/pyopenssl/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
