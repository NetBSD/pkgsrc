# $NetBSD: Makefile,v 1.2 2003/05/30 11:22:37 epg Exp $

PKGNAME=	swig-python-${SWIG_VERSION}
COMMENT=	Simplified Wrapper and Interface Generator, Python runtime

.include "../swig-build/Makefile.common"

PYTHON_VERSION_REQD=	22 22pth

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

ALL_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
