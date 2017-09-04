# $NetBSD: Makefile,v 1.13 2017/09/04 18:55:08 wiz Exp $

VERSION=	0.4.0
DISTNAME=	fs-${VERSION}
PKGNAME=	${PYPKGPREFIX}-filesystem-${VERSION}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://pyfilesystem.googlecode.com/files/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	https://github.com/PyFilesystem/pyfilesystem
COMMENT=	Python filesystem access library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.4.0

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
