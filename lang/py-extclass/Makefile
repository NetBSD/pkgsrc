# $NetBSD: Makefile,v 1.1.1.1 1999/12/30 21:37:02 tsarna Exp $
#

DISTNAME=	Zope-2.1.1-src
PKGNAME=	py-extclass-2.1.1
CATEGORIES=	www
MASTER_SITES=   http://www.zope.org/Products/Zope/2.1.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.digicool.com/releases/ExtensionClass

DEPENDS+=	python-1.5.2:../../lang/python

ALL_TARGET=	default
PYTHON_LIBDIR=		${LOCALBASE}/lib/python1.5/site-packages
PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config
EXTRACT_ELEMENTS=       Zope-2.1.1-src/lib/Components/ExtensionClass

WRKSRC=		${WRKDIR}/Zope-2.1.1-src/lib/Components/ExtensionClass

do-configure:
	( cd ${WRKSRC} ;\
	  ${CP} ${PYTHON_CONFIGDIR}/Makefile.pre.in . ;\
	  ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKSRC}; ${LOCALBASE}/bin/python ${PREFIX}/lib/python1.5/compileall.py .)
	(cd ${WRKSRC}; ${LOCALBASE}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py .)

do-install:
	(cd ${WRKSRC}; ${INSTALL_DATA} ExtensionClass.h \
		${LOCALBASE}/include/python1.5 ; \
	${INSTALL_SCRIPT} Xaq.py* ComputedAttribute.py* ${PYTHON_LIBDIR} ; \
	${INSTALL_PROGRAM} *.so ${PYTHON_LIBDIR} ; \
	${INSTALL_SCRIPT_DIR} ${PYTHON_LIBDIR}/extclass_test ; \
	${INSTALL_SCRIPT} test_*.py* ${PYTHON_LIBDIR}/extclass_test ; \
	${INSTALL_DATA_DIR} ${PYTHON_LIBDIR}/extclass_doc ; \
	${INSTALL_DATA} *.txt *.stx ${PYTHON_LIBDIR}/extclass_doc)
	

.include "../../mk/bsd.pkg.mk"
