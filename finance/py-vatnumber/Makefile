# $NetBSD: Makefile,v 1.11 2019/04/26 13:13:57 maya Exp $

DISTNAME=		vatnumber-1.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		finance python
MASTER_SITES=		${MASTER_SITE_PYPI:=v/vatnumber/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pypi.python.org/pypi/vatnumber/
COMMENT=		Python module to validate VAT numbers
LICENSE=		gnu-gpl-v3

DEPENDS+=		${PYPKGPREFIX}-stdnum-[0-9]*:../../misc/py-stdnum

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-simplesoap via py-stdnum

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
