# $NetBSD: Makefile,v 1.3 1999/08/06 00:32:16 sakamoto Exp $
# FreeBSD Id: Makefile,v 1.4 1999/05/19 09:41:06 tg Exp $

DISTNAME=	sketch-0.6.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.online.de/home/sketch/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.online.de/home/sketch/

DEPENDS+=	py-imaging-1.0b1:../../graphics/py-imaging
DEPENDS+=	py-Tk-1.5.2:../../x11/py-Tk

SKETCHDIR=	${PREFIX}/share/sketch
SKETCHDOCDIR=	${PREFIX}/share/doc/sketch
SKETCHDOCS=	BUGS Doc NEWS PROJECTS README TODO
SKETCHEXDIR=	${PREFIX}/share/examples/sketch

do-configure:
	@(cd ${WRKSRC} && \
	    python setup.py configure --imaging-include=${PREFIX}/include/PIL)

do-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} python setup.py build)

do-install:
	${MKDIR} ${SKETCHDIR}
.for dir in Filter Pax Plugins Resources Script Sketch
	(cd ${WRKSRC}; tar -c -f - --exclude-from=${FILESDIR}/excludelist ${dir}) | \
	    (cd ${SKETCHDIR}/; tar xf -)
.endfor
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} finishinst.py sk2ps.py sketch.py ${SKETCHDIR})
	${MKDIR} ${SKETCHDOCDIR}
	(cd ${WRKSRC}; tar cf - ${SKETCHDOCS}) | (cd ${SKETCHDOCDIR}; tar xf -)
	${MKDIR} ${SKETCHEXDIR}
	(cd ${WRKSRC}/Examples; tar cf - .) | (cd ${SKETCHEXDIR}; tar xf -)
	(cd ${SKETCHDIR}; python finishinst.py)
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sketch.in > ${PREFIX}/bin/sketch
	chmod +x ${PREFIX}/bin/sketch
	${SED} -e "s|@PREFIX@|${PREFIX}|g" < ${FILESDIR}/sk2ps.in > ${PREFIX}/bin/sk2ps
	chmod +x ${PREFIX}/bin/sk2ps

.include "../../mk/bsd.pkg.mk"
