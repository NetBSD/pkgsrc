# $NetBSD: Makefile,v 1.34 2020/06/05 12:49:13 jperkin Exp $

PKGREVISION= 1
.include "../../multimedia/ming/Makefile.common"

PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/_/./g}
CATEGORIES=		multimedia

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.libming.org/
COMMENT=		Python bindings for Ming library
LICENSE=		gnu-lgpl-v2.1

PY_PATCHPLIST=		yes
PYSETUPSUBDIR=		py_ext
EGG_NAME=		${DISTNAME:S/ming/mingc/:S/_/./g}

PYTHON_VERSIONS_ACCEPTED=	27

pre-configure:
	cd ${WRKSRC}/py_ext; \
	sed -e 's/@srcdir@/./' -e 's/@ZLIB@/-lz/' -e 's/@PNGLIB@/-lpng/' -e 's/@GIFLIB@/-lgif/' \
	-e "s/@MING_VERSION@/${MING_VERSION}/" < setup.py.in > setup.py

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ming/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
