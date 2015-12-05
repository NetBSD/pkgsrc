# $NetBSD: Makefile,v 1.3 2015/12/05 21:25:57 adam Exp $

CYBOX_VERSION=	2.1.0.4
DISTNAME=	python-cybox-${CYBOX_VERSION}
PKGNAME=	${PYPKGPREFIX}-cybox-${CYBOX_VERSION}
CATEGORIES=	security
DISTFILES=	v${CYBOX_VERSION}${EXTRACT_SUFX}
MASTER_SITES=	https://github.com/CybOXProject/python-cybox/archive/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/CybOXProject/python-cybox
COMMENT=	Python library for manipulating CybOX content
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

EGG_NAME=	cybox-${CYBOX_VERSION}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
