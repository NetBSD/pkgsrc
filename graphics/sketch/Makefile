# $NetBSD: Makefile,v 1.27 2003/07/28 09:18:56 drochner Exp $
#

DISTNAME=	sketch-0.6.15
CATEGORIES=	graphics
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=sketch/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://sketch.sourceforge.net/
COMMENT=	Interactive drawing program

USE_X11=	YES
USE_BUILDLINK2=	yes

PYTHON_PATCH_SCRIPTS= sk2ppm.py sk2ps.py skconvert.py sketch.py skshow.py
SK_CONF_ARGS=	--imaging-include=${BUILDLINK_PREFIX.pyimaging}/${PYINC}/PIL
SK_TKFLAGS=	-L${BUILDLINK_PREFIX.tk}/lib -R${BUILDLINK_PREFIX.tk}/lib -ltk -ltcl
SK_TKFLAGS+=	-R${X11BASE}/lib
SK_CONF_ARGS+=	--tk-flags=${SK_TKFLAGS:Q}

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	    ${PYTHONBIN} setup.py configure ${SK_CONF_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py install \
		--prefix=${PREFIX}

SKETCHDOCDIR=	${PREFIX}/share/doc/sketch
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/sketch

post-install:
	${INSTALL_DATA_DIR} ${SKETCHDOCDIR}
	cd ${WRKSRC} && ${PAX} -rw -v ${SKETCHDOCS} ${SKETCHDOCDIR}
	${INSTALL_DATA_DIR} ${SKETCHEXDIR}
	cd ${WRKSRC}/Examples && ${PAX} -rw -v . ${SKETCHEXDIR}

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../graphics/py-imaging/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
