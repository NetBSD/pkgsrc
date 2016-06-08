# $NetBSD: Makefile,v 1.5 2016/06/08 17:43:38 wiz Exp $

DISTNAME=	stix-1.1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stix/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/STIXProject/python-stix
COMMENT=	Python library for manipulating STIX content
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
