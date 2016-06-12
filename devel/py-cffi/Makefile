# $NetBSD: Makefile,v 1.19 2016/06/12 21:47:28 riastradh Exp $

DISTNAME=	cffi-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cffi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/cffi/
COMMENT=	Foreign Function Interface for Python calling C code
LICENSE=	mit

USE_TOOLS+=	pkg-config

DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

.include "../../devel/libffi/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
