# $NetBSD: Makefile,v 1.4 2003/08/17 18:10:35 recht Exp $

PKGNAME=	swig-python-${SWIG_VERSION}
COMMENT=	Simplified Wrapper and Interface Generator, Python runtime

.include "../swig-build/Makefile.common"

PYTHON_VERSION_ACCEPTED=	23 23pth 22 22pth

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

ALL_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
