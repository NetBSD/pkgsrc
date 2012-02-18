# $NetBSD: Makefile,v 1.5 2012/02/18 21:18:02 gls Exp $
#

VERSION=	0.5.29
DISTNAME=	pycryptopp-${VERSION}
PKGNAME=	${PYPKGPREFIX}-cryptopp-${VERSION}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pycryptopp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tahoe-lafs.org/trac/pycryptopp
COMMENT=	Python wrapper for (and copy of parts of) crypto++

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

REPLACE_INTERPRETER+=  python
REPLACE.python.old=    /usr/bin/env python
REPLACE.python.new=    ${PYTHONBIN}
REPLACE_FILES.python=  pycryptopp/test/*.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
