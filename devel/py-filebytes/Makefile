# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:04 wiz Exp $

DISTNAME=	filebytes-0.9.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=sashs/}
GITHUB_PROJECT=	filebytes
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sashs/filebytes/
COMMENT=	Library to read and edit ELF, PE, MachO and OAT files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
