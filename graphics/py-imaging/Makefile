# $NetBSD: Makefile,v 1.12 2002/02/14 11:39:46 drochner Exp $

DISTNAME=	Imaging-1.1.2
PKGNAME=	${PYPKGPREFIX}-imaging-1.1.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/downloads/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/pil/
COMMENT=	PIL, the Python Imaging Library

DEPENDS+=	jpeg-6b:../../graphics/jpeg

DIST_SUBDIR=    python

PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

# this pkg uses Makefile.pre.in
PYTHON_VERSIONS_ACCEPTED=	20 21
BUILDLINK_DEPENDS.python20=	python20>=2.0.1nb1
BUILDLINK_DEPENDS.python21=	python21>=2.1.1nb1

PY_PATCHPLIST=	yes

do-configure:
	(cd ${WRKSRC}/libImaging; CC="cc -fPIC" LIBS="${LDFLAGS}" ./configure)
	${SED} -e 's,@PREFIX@,${PREFIX},g' ${FILESDIR}/Setup.in \
		>${WRKSRC}/Setup.in
	${CP} ${LOCALBASE}/${PYLIB}/config/Makefile.pre.in ${WRKSRC}
	(cd ${WRKSRC}; ${MAKE} -f Makefile.pre.in boot)

do-build:
	(cd ${WRKSRC}/libImaging; ${SETENV} ${MAKE_ENV} ${MAKE}; cd ..; ${MAKE})

post-build:
	(cd ${WRKSRC}/PIL; ${PYTHONBIN} ${PREFIX}/${PYLIB}/compileall.py .)
	(cd ${WRKSRC}/PIL; ${PYTHONBIN} -O ${PREFIX}/${PYLIB}/compileall.py .)

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA_DIR} ${PREFIX}/${PYSITELIB}/PIL
	${INSTALL_SCRIPT} ${WRKSRC}/PIL.pth \
		${PREFIX}/${PYSITELIB}
	${INSTALL_SCRIPT} ${WRKSRC}/_imaging.so \
		${WRKSRC}/PIL/*.py ${WRKSRC}/PIL/*.py[co] \
		${PREFIX}/${PYSITELIB}/PIL
	${INSTALL_DATA_DIR} ${PREFIX}/${PYINC}/PIL
	${INSTALL_DATA} ${WRKSRC}/libImaging/*.h ${PREFIX}/${PYINC}/PIL
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}/PIL; ${FIND} . -name \*.py\* -print \
		| ${SED} -e 's,^./,${PYSITELIB}/PIL/,g' \
		>>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} ${PYINC}/PIL -type f -print >>${PLIST_SRC})
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PYPKGPREFIX}-imaging
	(cd ${WRKSRC}/Scripts; \
	 for i in  README bdf2pil.py explode.py gifmaker.py image2py.py pil*.py; do \
	 ${INSTALL_DATA} $$i ${PREFIX}/share/examples/${PYPKGPREFIX}-imaging; \
	 ${ECHO} share/examples/${PYPKGPREFIX}-imaging/$$i >>${PLIST_SRC}; done )
	${ECHO} "@dirrm share/examples/${PYPKGPREFIX}-imaging" >>${PLIST_SRC}
	${ECHO} "@dirrm ${PYINC}/PIL" >>${PLIST_SRC}
	${ECHO} "@dirrm ${PYSITELIB}/PIL" >> ${PLIST_SRC}

.include "../../lang/python/extension.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
