# $NetBSD: Makefile,v 1.31 2014/02/12 23:18:35 tron Exp $

DISTNAME=	pyOpenSSL-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyOpenSSL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/pyopenssl/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

.include "../../lang/python/distutils.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
