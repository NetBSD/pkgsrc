# $NetBSD: Makefile,v 1.39 2016/12/01 14:51:15 wiz Exp $

DISTNAME=		M2Crypto-0.22.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=		1
CATEGORIES=		security python
MASTER_SITES=		${MASTER_SITE_PYPI:=M/M2Crypto/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://chandlerproject.org/bin/view/Projects/MeTooCrypto
COMMENT=		Crypto and SSL toolkit for Python
LICENSE=		m2crypto-license

PYSETUPBUILDARGS=	build_ext --openssl=${BUILDLINK_PREFIX.openssl}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.21.1

.include "../../lang/python/egg.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
