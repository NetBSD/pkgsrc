# $NetBSD: Makefile,v 1.6 2014/12/31 13:57:25 wiz Exp $

DISTNAME=	python-cdb-0.35
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	databases
MASTER_SITES=	https://pypi.python.org/packages/source/p/python-cdb/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pilcrow.madison.wi.us/
COMMENT=	Python extension module for cdb
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
