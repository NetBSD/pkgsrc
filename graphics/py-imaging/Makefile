# $NetBSD: Makefile,v 1.10 2002/01/02 10:21:44 hubertf Exp $

DISTNAME=	Imaging-1.1.1
PKGNAME=	py-imaging-1.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/downloads/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

DEPENDS+=	python>=2.0:../../lang/python
DEPENDS+=	jpeg-6b:../../graphics/jpeg

DIST_SUBDIR=    python

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

do-configure:
	(cd ${WRKSRC}/libImaging; CC="cc -fPIC" LIBS="${LDFLAGS}" ./configure)
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${FILESDIR}/Setup.in \
		>${WRKSRC}/Setup.in
	(cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot)

do-build:
	(cd ${WRKSRC}/libImaging; ${SETENV} ${MAKE_ENV} ${MAKE}; cd ..; ${MAKE})

post-build:
	(cd ${WRKSRC}/PIL; python ${PREFIX}/lib/python2.0/compileall.py .)
	(cd ${WRKSRC}/PIL; python -O ${PREFIX}/lib/python2.0/compileall.py .)

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/python2.0/site-packages
	${INSTALL_DATA_DIR} ${PREFIX}/lib/python2.0/site-packages/PIL
	${INSTALL_SCRIPT} ${WRKSRC}/PIL.pth \
		${PREFIX}/lib/python2.0/site-packages
	${INSTALL_SCRIPT} ${WRKSRC}/_imaging.so \
		${WRKSRC}/PIL/*.py ${WRKSRC}/PIL/*.py[co] \
		${PREFIX}/lib/python2.0/site-packages/PIL
	${INSTALL_DATA_DIR} ${PREFIX}/include/PIL
	${INSTALL_DATA} ${WRKSRC}/libImaging/*.h ${PREFIX}/include/PIL
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}/PIL; ${FIND} . -name \*.py\* -print \
		| ${SED} -e 's,^./,lib/python2.0/site-packages/PIL/,g' \
		>>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} include/PIL -type f -print >>${PLIST_SRC})
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/py-imaging
	(cd ${WRKSRC}/Scripts; \
	 for i in  README bdf2pil.py explode.py gifmaker.py image2py.py pil*.py; do \
	 ${INSTALL_DATA} $$i ${PREFIX}/share/examples/py-imaging; \
	 ${ECHO} share/examples/py-imaging/$$i >>${PLIST_SRC}; done )
	${ECHO} "@dirrm share/examples/py-imaging" >>${PLIST_SRC}
	${ECHO} "@dirrm include/PIL" >>${PLIST_SRC}
	${ECHO} "@dirrm lib/python2.0/site-packages/PIL" >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
