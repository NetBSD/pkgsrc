# $NetBSD: Makefile,v 1.21 2002/08/30 08:06:14 drochner Exp $
#

DISTNAME=	sketch-0.6.13
CATEGORIES=	graphics
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=sketch/}

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://sketch.sourceforge.net/
COMMENT=	Interactive drawing program

USE_X11=	YES

PYTHON_VERSIONS_ACCEPTED= 20 # XXX until some things are cleaned up

SKETCHDIR=	${PREFIX}/share/sketch
SKETCHDOCDIR=	${PREFIX}/share/doc/sketch
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/sketch

echo:
	${ECHO} ${LIBS}

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	    ${PYTHONBIN} setup.py configure \
		--imaging-include=${PREFIX}/include/python2.0/PIL)

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build)

do-install:
	${INSTALL_DATA_DIR} ${SKETCHDIR}
.for dir in Filter Pax Plugins Resources Script Sketch
	(cd ${WRKSRC}; ${GTAR} -c -f - --exclude-from=${FILESDIR}/excludelist ${dir}) | \
	    (cd ${SKETCHDIR}/; ${GTAR} xf -)
.endfor
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} finishinst.py sk2ps.py sketch.py ${SKETCHDIR})
	${INSTALL_DATA_DIR} ${SKETCHDOCDIR}
	cd ${WRKSRC} && ${PAX} -rw -pe -v ${SKETCHDOCS} ${SKETCHDOCDIR}
	${INSTALL_DATA_DIR} ${SKETCHEXDIR}
	cd ${WRKSRC}/Examples && ${PAX} -rw -pe -v . ${SKETCHEXDIR}
	(cd ${SKETCHDIR}; ${PYTHONBIN} finishinst.py)
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sketch.in > ${PREFIX}/bin/sketch
	${CHMOD} +x ${PREFIX}/bin/sketch
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sk2ps.in > ${PREFIX}/bin/sk2ps
	${CHMOD} +x ${PREFIX}/bin/sk2ps

.include "../../lang/python/application.buildlink.mk"
.include "../../x11/py-Tk/buildlink.mk"
.include "../../graphics/py-imaging/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
