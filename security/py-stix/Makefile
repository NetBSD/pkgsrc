# $NetBSD: Makefile,v 1.4 2015/12/05 21:25:57 adam Exp $

DISTNAME=	stix-1.1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	https://pypi.python.org/packages/source/s/stix/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/STIXProject/python-stix
COMMENT=	Python library for manipulating STIX content
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
