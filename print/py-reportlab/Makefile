# $NetBSD: Makefile,v 1.6 2002/09/21 23:46:55 jlam Exp $
#

DISTNAME=	ReportLab_1_01
PKGNAME=	${PYPKGPREFIX}-reportlab-1.01
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.reportlab.com/
COMMENT=	powerful PDF-generating toolkit for Python

WRKSRC=		${WRKDIR}/reportlab/lib

ALL_TARGET=	default
PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

PYTHON_VERSIONS_ACCEPTED= 20 21 # no 22 - uses Makefile.pre.in
PYBINMODULE= yes

do-configure:
	(cd ${WRKSRC} ;\
	  ${CP} ${LOCALBASE}/${PYLIB}/config/Makefile.pre.in . ;\
	  ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKDIR}; \
	${PYTHONBIN} ${LOCALBASE}/${PYLIB}/compileall.py . ; \
	${PYTHONBIN} -O ${LOCALBASE}/${PYLIB}/compileall.py . )
	(cd ${WRKSRC}; \
	${MAKE} clean; ${RM} -f *.c *.orig Makefile* Setup* sedscript )

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; ${PAX} -r -w -v -p p reportlab ${PREFIX}/${PYSITELIB})
	(cd ${PREFIX}; ${FIND} ${PYSITELIB}/reportlab \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PYSITELIB}/reportlab \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
