# $NetBSD: Makefile,v 1.1 2021/01/16 20:40:05 khorben Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-filecheck-2020.08.07
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=OctoPrint/}
GITHUB_PROJECT=	OctoPrint-FileCheck
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FileCheck/
COMMENT=	Checks for common issues in uploaded files
LICENSE=	gnu-agpl-v3

EGG_NAME=	OctoPrint_FileCheck-2020.8.7

PYTHON_VERSIONS_ACCEPTED=	39 38 37 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
