# $NetBSD: Makefile,v 1.32 2014/02/12 23:18:36 tron Exp $

DISTNAME=		M2Crypto-0.21.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=		3
CATEGORIES=		security python
MASTER_SITES=		http://pypi.python.org/packages/source/M/M2Crypto/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://chandlerproject.org/bin/view/Projects/MeTooCrypto
COMMENT=		Crypto and SSL toolkit for Python
LICENSE=		m2crypto-license

# constness is very different between openssl versions,
# it seems, and 0.9.7i is the version which currently is
# in pkgsrc and against which I fixed m2crypto to compile.
# -- wiz 20060115
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.7i{,nb*}

PYSETUPBUILDARGS=	build_ext --openssl=${BUILDLINK_PREFIX.openssl}

PYTHON_VERSIONS_INCOMPATIBLE=	33 # not yet ported as of 0.21.1

.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
