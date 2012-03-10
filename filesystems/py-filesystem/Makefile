# $NetBSD: Makefile,v 1.3 2012/03/10 19:48:06 wiz Exp $
#

VERSION=	0.4.0
DISTNAME=	fs-${VERSION}
PKGNAME=	${PYPKGPREFIX}-filesystem-${VERSION}
CATEGORIES=	filesystems
MASTER_SITES=	http://pyfilesystem.googlecode.com/files/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://code.google.com/p/pyfilesystem/
COMMENT=	Python filesystem access library
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24

USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
