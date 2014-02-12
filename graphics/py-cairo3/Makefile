# $NetBSD: Makefile,v 1.5 2014/02/12 00:30:03 prlw1 Exp $

DISTNAME=		pycairo-1.10.0
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		leuzi@trash.net
HOMEPAGE=		http://cairographics.org/pycairo/
COMMENT=		Python bindings for cairo (python-3.x version)
LICENSE=		gnu-lgpl-v2.1 OR mpl-1.1

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal automake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PKGCONFIG_OVERRIDE+=	py3cairo.pc.in
PYTHON_VERSIONS_INCOMPATIBLE=	26 27
PY_PATCHPLIST=		yes
# waf is not smart enough for this as of 1.10.0
PY_PEP3147=		no

do-configure:
	cd ${WRKSRC:Q} && \
		${SETENV} ${CONFIGURE_ENV} ${PYTHONBIN} ./waf configure \
			--destdir=${DESTDIR} --prefix=${PREFIX} \
			--mandir=${PREFIX}/${PKGMANDIR}

do-build:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHONBIN} ./waf build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} ./waf install

.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10
.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
