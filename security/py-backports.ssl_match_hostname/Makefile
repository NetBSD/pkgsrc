# $NetBSD: Makefile,v 1.5 2016/06/01 12:36:39 wiz Exp $

DISTNAME=	backports.ssl_match_hostname-3.5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security www
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.ssl_match_hostname/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/backports.ssl_match_hostname
COMMENT=	Python SSL support module for Python 2
LICENSE=	python-software-foundation

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # included in 3.2+

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
