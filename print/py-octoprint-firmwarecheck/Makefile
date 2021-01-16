# $NetBSD: Makefile,v 1.1 2021/01/16 18:56:27 khorben Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-firmwarecheck-2020.09.23
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=OctoPrint/}
GITHUB_PROJECT=	OctoPrint-FirmwareCheck
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FirmwareCheck/
COMMENT=	Checks for unsafe or broken printer firmwares
LICENSE=	gnu-agpl-v3

EGG_NAME=	OctoPrint_FirmwareCheck-2020.9.23

PYTHON_VERSIONS_ACCEPTED=	39 38 37 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
