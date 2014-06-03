# $NetBSD: Makefile,v 1.3 2014/06/03 08:59:33 khorben Exp $

DISTNAME=	stix-1.1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	https://pypi.python.org/packages/source/s/stix/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/STIXProject/python-stix
COMMENT=	Python library for manipulating STIX content
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
