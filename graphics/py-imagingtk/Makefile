# $NetBSD: Makefile,v 1.1.1.1 2001/03/20 16:47:09 wiz Exp $
#

DISTNAME=	Imaging-1.1.1
PKGNAME=	py-imagingtk-1.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/downloads/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	Tk support for the Python Imaging Library (PIL)

DEPENDS+=	py-imaging>=1.1.1:../../graphics/py-imaging
DEPENDS+=	py-Tk>=2.0:../../x11/py-Tk

DIST_SUBDIR=    python
ALL_TARGET=     sharedmods

do-configure:
	(cd ${WRKSRC}/libImaging; CC="cc -fPIC" LIBS="${LDFLAGS}" ./configure)
	${SED} -e 's,@PREFIX@,${PREFIX},g' -e 's,@X11BASE@,${X11BASE},g' \
	        ${FILESDIR}/Setup.in >${WRKSRC}/Setup.in
	(cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot)

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/_imagingtk.so \
		${PREFIX}/lib/python2.0/site-packages/PIL
	(cd ${WRKSRC}/Scripts; \
	${INSTALL_DATA} enhancer.py painter.py player.py \
	thresholder.py viewer.py ${PREFIX}/share/examples/py-imaging )

.include "../../mk/bsd.pkg.mk"
