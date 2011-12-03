# $NetBSD: Makefile,v 1.25 2011/12/03 00:02:16 joerg Exp $

DISTNAME=	pyOpenSSL-0.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyOpenSSL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/pyopenssl/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
