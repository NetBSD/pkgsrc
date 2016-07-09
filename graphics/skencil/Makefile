# $NetBSD: Makefile,v 1.36 2016/07/09 13:03:52 wiz Exp $

DISTNAME=	skencil-0.6.17
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sketch/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://sketch.sourceforge.net/
COMMENT=	Interactive drawing program

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_TOOLS+=	pax

REPLACE_PYTHON= sk2ppm.py sk2ps.py skconvert.py skencil.py skshow.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # py-imaging

SK_CONF_ARGS=	--imaging-include=${BUILDLINK_PREFIX.pyimaging}/${PYINC}/PIL
SK_TKFLAGS=	-L${BUILDLINK_PREFIX.tk}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.tk}/lib -ltk -ltcl
SK_TKFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib
SK_CONF_ARGS+=	--tk-flags=${SK_TKFLAGS:Q}

CPPFLAGS+=	-DUSE_INTERP_RESULT

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	    ${PYTHONBIN} setup.py configure ${SK_CONF_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py install \
		--prefix=${PREFIX} --dest-dir=${DESTDIR}

SKETCHDOCDIR=	${PREFIX}/share/doc/skencil
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/skencil

INSTALLATION_DIRS=	${SKETCHDOCDIR} ${SKETCHEXDIR}

post-install:
	cd ${WRKSRC} && pax -rw -pm -v ${SKETCHDOCS} ${DESTDIR}${SKETCHDOCDIR}
	${RM} ${DESTDIR}${SKETCHDOCDIR}/Doc/fonts.alias
	${RM} ${DESTDIR}${SKETCHDOCDIR}/Doc/fonts.scale
	cd ${WRKSRC}/Examples && pax -rwpm -v . ${DESTDIR}${SKETCHEXDIR}

.include "../../lang/python/application.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
