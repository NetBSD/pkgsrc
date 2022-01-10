# $NetBSD: Makefile,v 1.15 2022/01/10 20:28:24 wiz Exp $

DISTNAME=	python-cdb-0.35
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-cdb/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pilcrow.madison.wi.us/
COMMENT=	Python extension module for cdb
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
