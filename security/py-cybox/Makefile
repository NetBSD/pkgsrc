# $NetBSD: Makefile,v 1.5 2017/01/01 14:43:55 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36

EGG_NAME=	cybox-${CYBOX_VERSION}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
