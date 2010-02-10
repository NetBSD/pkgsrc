# $NetBSD: Makefile,v 1.17 2010/02/10 19:17:40 joerg Exp $
#

DISTNAME=	skencil-0.6.17
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sketch/}

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://sketch.sourceforge.net/
COMMENT=	Interactive drawing program

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

PYTHON_PATCH_SCRIPTS= sk2ppm.py sk2ps.py skconvert.py skencil.py skshow.py
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
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
