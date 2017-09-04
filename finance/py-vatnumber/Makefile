# $NetBSD: Makefile,v 1.9 2017/09/04 18:55:08 wiz Exp $

DISTNAME=		vatnumber-1.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		finance python
MASTER_SITES=		${MASTER_SITE_PYPI:=v/vatnumber/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/vatnumber/
COMMENT=		Python module to validate VAT numbers
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-stdnum-[0-9]*:../../misc/py-stdnum

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-simplesoap via py-stdnum

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
