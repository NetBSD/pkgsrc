# $NetBSD: Makefile,v 1.43 2022/07/05 08:16:14 adam Exp $

DISTNAME=	pycryptodome-3.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycryptodome/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pycryptodome.org/
COMMENT=	Cryptographic and hash functions for Python
LICENSE=	public-domain AND python-software-foundation

# XXX is this needed?
CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

CHECK_PORTABILITY_SKIP=	appveyor/get_wheels.sh

.include "../../lang/python/egg.mk"

# Python 3 builds of this package get an extra "abi3" suffix added
.if ${_PYTHON_VERSION} != 27
PLIST_SUBST+=	SOEXT="abi3.so"
.else
PLIST_SUBST+=	SOEXT="so"
.endif

BUILDLINK_API_DEPENDS.gmp+=	gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
