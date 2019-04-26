# $NetBSD: Makefile,v 1.12 2019/04/26 13:13:46 maya Exp $

DISTNAME=	python-cdb-0.35
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-cdb/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pilcrow.madison.wi.us/
COMMENT=	Python extension module for cdb
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # not yet ported as of 0.35

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
