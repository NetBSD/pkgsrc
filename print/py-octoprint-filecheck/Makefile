# $NetBSD: Makefile,v 1.3 2021/10/06 07:48:51 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-filecheck-2021.2.23
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=OctoPrint/}
GITHUB_PROJECT=	OctoPrint-FileCheck
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FileCheck/
COMMENT=	Checks for common issues in uploaded files
LICENSE=	gnu-agpl-v3

EGG_NAME=	OctoPrint_FileCheck-2021.2.23

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
