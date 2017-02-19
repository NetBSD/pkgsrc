# $NetBSD: Makefile,v 1.41 2017/02/19 18:54:39 adam Exp $

DISTNAME=	M2Crypto-0.25.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/M2Crypto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://chandlerproject.org/bin/view/Projects/MeTooCrypto
COMMENT=	Crypto and SSL toolkit for Python
LICENSE=	m2crypto-license

DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing

PYSETUPBUILDARGS=	build_ext --openssl=${BUILDLINK_PREFIX.openssl}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.25.1

.include "../../lang/python/egg.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
