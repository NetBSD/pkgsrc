# $NetBSD: Makefile,v 1.11 2022/01/04 20:53:08 wiz Exp $

DISTNAME=	google-apputils-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-apputils/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/google/google-apputils
COMMENT=	Google Application Utilities for Python
LICENSE=	apache-2.0

PYTHON_VERSIONS_ACCEPTED=	27

# https://github.com/google/google-apputils/issues/4
post-extract:
	${CHMOD} 644 ${WRKSRC}/google_apputils.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
