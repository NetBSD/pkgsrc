# $NetBSD: Makefile,v 1.10 2002/01/22 18:26:19 drochner Exp $
#

DISTNAME=	Zope-2.2.2-src
PKGNAME=	py-extclass-2.2.2
CATEGORIES=	lang
MASTER_SITES=   http://www.zope.org/Products/Zope/2.2.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.digicool.com/releases/ExtensionClass
COMMENT=	Python-extensible C "classes" and Acquisition for Python

EXTRACT_ELEMENTS=       ${DISTNAME}/lib/Components/ExtensionClass

WRKSRC=		${WRKDIR}/${DISTNAME}/lib/Components/ExtensionClass

do-configure:
	( cd ${WRKSRC} ;\
	  ${CP} ${PY_CONFIGDIR}/Makefile.pre.in . ;\
	  ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKSRC}; ${PY_PROG} ${PY_LIBDIR}/compileall.py .)
	(cd ${WRKSRC}; ${PY_PROG} -O ${PY_LIBDIR}/compileall.py .)

do-install:
	(cd ${WRKSRC}; ${INSTALL_DATA} ExtensionClass.h ${PY_INCDIR} ; \
	${INSTALL_SCRIPT_DIR} ${PY_SITEPKG} ; \
	${INSTALL_SCRIPT} Xaq.py* ${PY_SITEPKG} ; \
	${INSTALL_PROGRAM} *.so ${PY_SITEPKG} ; \
	${INSTALL_SCRIPT_DIR} ${PY_SITEPKG}/extclass_test ; \
	${INSTALL_SCRIPT} test_*.py* ${PY_SITEPKG}/extclass_test ; \
	${INSTALL_DATA_DIR} ${PY_SITEPKG}/extclass_doc ; \
	${INSTALL_DATA} *.txt *.stx ${PY_SITEPKG}/extclass_doc)

.include "../../lang/python20/Makefile.inc"
.include "../../mk/bsd.pkg.mk"
