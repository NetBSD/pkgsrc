# $NetBSD: Makefile,v 1.13 2001/05/09 13:11:26 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1999/05/19 09:41:06 tg Exp $

DISTNAME=	sketch-0.6.3
CATEGORIES=	graphics
MASTER_SITES=   ${MASTER_SITE_BACKUP}

MAINTAINER=	packages@netbsd.org
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
	(cd ${WRKSRC}; ${GTAR} cf - ${SKETCHDOCS}) | (cd ${SKETCHDOCDIR}; ${GTAR} xf -)
	${INSTALL_DATA_DIR} ${SKETCHEXDIR}
	(cd ${WRKSRC}/Examples; ${GTAR} cf - .) | (cd ${SKETCHEXDIR}; ${GTAR} xf -)
	(cd ${SKETCHDIR}; python finishinst.py)
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sketch.in > ${PREFIX}/bin/sketch
	${CHMOD} +x ${PREFIX}/bin/sketch
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sk2ps.in > ${PREFIX}/bin/sk2ps
	${CHMOD} +x ${PREFIX}/bin/sk2ps

.include "../../mk/bsd.pkg.mk"
