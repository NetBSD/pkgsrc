# $NetBSD: Makefile,v 1.32 2020/07/03 03:03:18 gutteridge Exp $

DISTNAME=	pycryptodome-3.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycryptodome/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pycryptodome.org/
COMMENT=	Cryptographic and hash functions for Python
LICENSE=	public-domain AND python-software-foundation

EXTRACT_USING=	bsdtar

# XXX is this needed?
CFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

CHECK_PORTABILITY_SKIP=	appveyor/get_wheels.sh

BUILDLINK_API_DEPENDS.gmp+=	gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
