# $NetBSD: Makefile,v 1.2 2010/07/23 01:17:42 gdt Exp $
#

DISTNAME=	pycryptopp-0.5.19
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-cryptopp-0.5.19
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pycryptopp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/trac/pycryptopp
COMMENT=	Python wrapper for (and copy of parts of) crypto++

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
