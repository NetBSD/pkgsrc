# $NetBSD: Makefile,v 1.7 2000/12/28 15:08:46 wiz Exp $

DISTNAME=	Imaging-1.0b1
PKGNAME=	py-imaging-1.0b1
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/downloads/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.pythonware.com/products/pil/

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
	(cd ${WRKSRC}/libImaging; ${MAKE}; cd ..; ${MAKE})

post-build:
	(cd ${WRKSRC}/PIL; python ${PREFIX}/lib/python2.0/compileall.py .)
	(cd ${WRKSRC}/PIL; python -O ${PREFIX}/lib/python2.0/compileall.py .)

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/PIL/*.py ${WRKSRC}/PIL/*.py[co] \
		${PREFIX}/lib/python2.0/site-packages
	${INSTALL_DATA_DIR} ${PREFIX}/include/PIL
	${INSTALL_DATA} ${WRKSRC}/libImaging/*.h ${PREFIX}/include/PIL
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}/PIL; ${FIND} . -name \*.py\* -print \
		| ${SED} -e 's,^./,lib/python2.0/site-packages/,g' \
		>>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} include/PIL -type f -print >>${PLIST_SRC})
	${ECHO} "@dirrm include/PIL" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
