# $NetBSD: Makefile,v 1.1.1.1 2003/05/25 08:50:07 epg Exp $

PKGNAME=	swig-python-${SWIG_VERSION}
COMMENT=	Simplified Wrapper and Interface Generator, Python runtime

.include "../swig-build/Makefile.common"

PYTHON_VERSION_REQD=	22

CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}

ALL_TARGET=		runtime
INSTALL_TARGET=		install-runtime

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
