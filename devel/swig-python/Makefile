# $NetBSD: Makefile,v 1.6 2004/10/03 00:13:33 tv Exp $

PKGNAME=	swig-python-${SWIG_VERSION}
PKGREVISION=	1
COMMENT=	Simplified Wrapper and Interface Generator, Python runtime

.include "../swig-build/Makefile.common"

PYTHON_VERSIONS_INCOMPATIBLE=	21 21pth 20 15

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

ALL_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
