# $NetBSD: Makefile,v 1.17 2001/11/22 13:08:41 hubertf Exp $
#

DISTNAME=	sketch-0.6.12
CATEGORIES=	graphics
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=sketch/}

MAINTAINER=	uebayasi@soum.co.jp
HOMEPAGE=	http://sketch.sourceforge.net/
COMMENT=	Interactive drawing program

DEPENDS+=	py-imaging>=1.0:../../graphics/py-imaging
DEPENDS+=	py-Tk>=1.5.2:../../x11/py-Tk

USE_X11=	YES

SKETCHDIR=	${PREFIX}/share/sketch
SKETCHDOCDIR=	${PREFIX}/share/doc/sketch
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/sketch

echo:
	${ECHO} ${LIBS}

do-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	    python setup.py configure --imaging-include=${PREFIX}/include/PIL)

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} python setup.py build)

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
	cd ${WRKSRC}/Examples && ${PAX} -rw . ${SKETCHEXDIR}
	(cd ${SKETCHDIR}; python finishinst.py)
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sketch.in > ${PREFIX}/bin/sketch
	${CHMOD} +x ${PREFIX}/bin/sketch
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sk2ps.in > ${PREFIX}/bin/sk2ps
	${CHMOD} +x ${PREFIX}/bin/sk2ps

.include "../../mk/bsd.pkg.mk"
