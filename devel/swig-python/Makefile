# $NetBSD: Makefile,v 1.5 2004/06/07 00:01:02 tv Exp $

PKGNAME=	swig-python-${SWIG_VERSION}
COMMENT=	Simplified Wrapper and Interface Generator, Python runtime

.include "../swig-build/Makefile.common"

PYTHON_VERSIONS_INCOMPATIBLE=	21 21pth 20 15

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

ALL_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
