# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:08 rillig Exp $

PKGNAME=	swig-python-${SWIG_VERSION}
PKGREVISION=	1
COMMENT=	Simplified Wrapper and Interface Generator, Python runtime

.include "../../devel/swig-build/Makefile.common"

PYTHON_VERSIONS_INCOMPATIBLE=	21 21pth 20 15

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

BUILD_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
