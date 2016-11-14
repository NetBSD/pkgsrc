# $NetBSD: Makefile,v 1.23 2016/11/14 14:31:18 wiz Exp $

DISTNAME=	cffi-1.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cffi/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

USE_TOOLS+=	pkg-config

DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

NOT_PAX_MPROTECT_SAFE=	${PYSITELIB}/_cffi_backend.so

# tests don't run on MPROTECT enabled systems, and I haven't found
# the magic to fix that, so workaround:
# sysctl -w security.pax.mprotect.global=0

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
