# $NetBSD: Makefile,v 1.4 2022/01/04 20:54:35 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-octoprint-firmwarecheck-2021.2.4
PKGREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_GITHUB:=OctoPrint/}
GITHUB_PROJECT=	OctoPrint-FirmwareCheck
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/OctoPrint/OctoPrint-FirmwareCheck/
COMMENT=	Checks for unsafe or broken printer firmwares
LICENSE=	gnu-agpl-v3

EGG_NAME=	OctoPrint_FirmwareCheck-2021.2.4

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
