# $NetBSD: Makefile,v 1.30 2014/01/25 10:30:19 wiz Exp $

DISTNAME=	pyOpenSSL-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyOpenSSL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/pyopenssl/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
