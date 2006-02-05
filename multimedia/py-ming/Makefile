# $NetBSD: Makefile,v 1.3 2006/02/05 23:10:18 joerg Exp $
#

DISTNAME=		${MING_DISTNAME}
PKGNAME=		${PYPKGPREFIX}-${MING_PKGNAME}
PKGREVISION=		1
CATEGORIES=		multimedia
MASTER_SITES=		${MING_MASTER_SITES}
EXTRACT_SUFX=		${MING_EXTRACT_SUFX}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://ming.sourceforge.net/
COMMENT=		Python bindings for Ming library

PY_PATCHPLIST=		yes
PYBINMODULE=		yes

BUILD_TARGET=		mingcmodule.so
BUILD_DIRS=		${WRKSRC}/py_ext

MAKE_ENV+=		PYSITELIB=${PYSITELIB:Q}

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

.include "../../multimedia/ming/buildlink3.mk"
.include "../../multimedia/ming/Makefile.common"
.include "../../lang/python/extension.mk"

post-build:
	${PYTHONBIN} ${PYCOMPILEALL} ${WRKSRC}/py_ext

post-install:
	${INSTALL_DATA} ${WRKSRC}/py_ext/ming.pyc ${PREFIX}/${PYSITELIB}

.include "../../mk/bsd.pkg.mk"
