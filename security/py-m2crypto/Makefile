# $NetBSD: Makefile,v 1.49 2018/11/13 13:31:02 adam Exp $

DISTNAME=	M2Crypto-0.31.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/M2Crypto/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/m2crypto/m2crypto
COMMENT=	Crypto and SSL toolkit for Python
LICENSE=	m2crypto-license

.include "../../lang/python/pyversion.mk"

PLIST_VARS+=	typing

.if ${_PYTHON_VERSION} == 27 || ${_PYTHON_VERSION} == 34
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
PLIST.typing=	yes
.endif

PYSETUPBUILDARGS=	build_ext --openssl=${BUILDLINK_PREFIX.openssl}

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
