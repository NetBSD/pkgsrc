# $NetBSD: Makefile,v 1.7 2017/01/01 14:43:56 wiz Exp $

DISTNAME=	stix-1.1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/stix/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/STIXProject/python-stix
COMMENT=	Python library for manipulating STIX content
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
