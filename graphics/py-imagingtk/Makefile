# $NetBSD: Makefile,v 1.7 2002/12/08 03:57:17 salo Exp $
#

DISTNAME=	Imaging-1.1.3
PKGNAME=	py20-imagingtk-1.1.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/downloads/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	Tk support for the Python Imaging Library (PIL)

PYTHON_VERSIONS_ACCEPTED= 20 # XXX for now until some things are cleaned up
BUILDLINK_DEPENDS.python20= python20>=2.0.1nb1

DIST_SUBDIR=    python
ALL_TARGET=     sharedmods
USE_BUILDLINK2=	yes
USE_X11=	yes

do-configure:
	(cd ${WRKSRC}/libImaging; CC="cc -fPIC" LIBS="${LDFLAGS}" ./configure)
	${CHMOD} +w ${WRKSRC}/Setup.in ${WRKSRC}/Makefile.pre.in
	${SED} -e 's,@PREFIX@,${PREFIX},g' -e 's,@X11BASE@,${X11BASE},g' \
	        ${FILESDIR}/Setup.in >${WRKSRC}/Setup.in
	${CP} ${LOCALBASE}/${PYLIB}/config/Makefile.pre.in ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/_imagingtk.so \
		${PREFIX}/lib/python2.0/site-packages/PIL
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py20-imaging
	(cd ${WRKSRC}/Scripts; \
	${INSTALL_DATA} enhancer.py painter.py player.py \
	thresholder.py viewer.py ${PREFIX}/share/examples/py20-imaging )

.include "../../lang/python/extension.mk"
.include "../../graphics/py-imaging/buildlink2.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
