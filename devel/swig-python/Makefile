# $NetBSD: Makefile,v 1.7 2004/12/03 15:14:55 wiz Exp $

PKGNAME=	swig-python-${SWIG_VERSION}
PKGREVISION=	1
COMMENT=	Simplified Wrapper and Interface Generator, Python runtime

.include "../swig-build/Makefile.common"

PYTHON_VERSIONS_INCOMPATIBLE=	21 21pth 20 15

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

BUILD_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
