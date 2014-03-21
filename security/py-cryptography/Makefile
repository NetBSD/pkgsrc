# $NetBSD: Makefile,v 1.2 2014/03/21 14:02:45 wiz Exp $

DISTNAME=	cryptography-0.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	https://pypi.python.org/packages/source/c/cryptography/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cryptography/
COMMENT=	Cryptographic recipes and primitives for Python
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cffi>=0.8:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser>=2.10:../../devel/py-cparser
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
