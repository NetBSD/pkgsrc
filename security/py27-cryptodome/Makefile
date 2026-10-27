# $NetBSD: Makefile,v 1.1 2026/10/27 11:52:14 wiz Exp $

DISTNAME=	pycryptodome-3.24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycryptodome/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pycryptodome.org/
COMMENT=	Cryptographic and hash functions for Python
LICENSE=	public-domain AND python-software-foundation

# "error: 'for' loop initial declarations are only allowed in C99 mode"
FORCE_C_STD=	c99

# XXX is this needed?
CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600

CHECK_PORTABILITY_SKIP=	appveyor/get_wheels.sh

PYTHON_27_ACCEPTED=		yes
PYTHON_VERSIONS_ACCEPTED=	#

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.gmp+=	gmp>=5.0
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
