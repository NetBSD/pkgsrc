# $NetBSD: Makefile,v 1.2 2015/08/28 10:51:42 wiz Exp $

DISTNAME=	google-apputils-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/source/g/google-apputils/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/google/google-apputils
COMMENT=	Google Application Utilities for Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	33 34

# https://github.com/google/google-apputils/issues/4
post-extract:
	${CHMOD} 644 ${WRKSRC}/google_apputils.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
