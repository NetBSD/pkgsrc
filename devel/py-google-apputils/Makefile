# $NetBSD: Makefile,v 1.8 2019/04/26 13:13:51 maya Exp $

DISTNAME=	google-apputils-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-apputils/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/google/google-apputils
COMMENT=	Google Application Utilities for Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_INCOMPATIBLE=	 36 37

# https://github.com/google/google-apputils/issues/4
post-extract:
	${CHMOD} 644 ${WRKSRC}/google_apputils.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
