# $NetBSD: Makefile,v 1.7 2012/10/04 00:22:00 cheusov Exp $
#

VERSION=	0.4.0
DISTNAME=	fs-${VERSION}
PKGNAME=	${PYPKGPREFIX}-filesystem-${VERSION}
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	http://pyfilesystem.googlecode.com/files/

MAINTAINER=	gdt@ir.bbn.com
HOMEPAGE=	http://code.google.com/p/pyfilesystem/
COMMENT=	Python filesystem access library
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
