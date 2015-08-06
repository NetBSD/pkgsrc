# $NetBSD: Makefile,v 1.2 2015/08/06 08:09:47 wiz Exp $

DISTNAME=	ipaddress-1.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES+=	https://pypi.python.org/packages/source/i/ipaddress/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/ipaddress
COMMENT=	Port of the python 3.3+ ipaddress module to 2.6 and 2.7
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # included in 3.3+

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
