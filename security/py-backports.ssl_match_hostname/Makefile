# $NetBSD: Makefile,v 1.1 2014/01/27 19:53:30 wiz Exp $

DISTNAME=	backports.ssl_match_hostname-3.4.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	https://pypi.python.org/packages/source/b/backports.ssl_match_hostname/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/backports.ssl_match_hostname
COMMENT=	Python SSL support module for Python 2
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	33 # included in 3.2+

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
