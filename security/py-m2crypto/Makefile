# $NetBSD: Makefile,v 1.42 2017/05/10 17:03:42 adam Exp $

DISTNAME=	M2Crypto-0.26.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/M2Crypto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/m2crypto/m2crypto
COMMENT=	Crypto and SSL toolkit for Python
LICENSE=	m2crypto-license

DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing

PYSETUPBUILDARGS=	build_ext --openssl=${BUILDLINK_PREFIX.openssl}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.26.0

.include "../../lang/python/egg.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
