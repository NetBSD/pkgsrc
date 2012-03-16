# $NetBSD: Makefile,v 1.6 2012/03/16 00:12:35 gdt Exp $
#

VERSION=	0.6.0.1206569328141510525648634803928199668821045408958
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

# It would be nice if egg.mk had support for this.
#TEST_TARGET=	@python@ setup.py test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
