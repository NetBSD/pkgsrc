# $NetBSD: Makefile,v 1.1.1.1 2000/08/31 22:39:45 tsarna Exp $
#

DISTNAME=	ReportLab_1_00
PKGNAME=	py-reportlab-1.00
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.reportlab.com/

DEPENDS+=	python-1.5.2:../../lang/python

WRKSRC=		${WRKDIR}/reportlab/pdfbase

ALL_TARGET=	default
PLIST_SRC=      ${WRKDIR}/.PLIST_SRC
SITE_PKG=               lib/python1.5/site-packages
PYTHON_LIBDIR=          ${LOCALBASE}/${SITE_PKG}
PYTHON_CONFIGDIR=	${LOCALBASE}/lib/python1.5/config

do-configure:
	(cd ${WRKSRC} ;\
	  ${CP} ${PYTHON_CONFIGDIR}/Makefile.pre.in . ;\
	  ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKDIR}; \
	${LOCALBASE}/bin/python ${PREFIX}/lib/python1.5/compileall.py . ; \
	${LOCALBASE}/bin/python -O ${PREFIX}/lib/python1.5/compileall.py . )
	(cd ${WRKSRC}; \
	${MAKE} clean; ${RM} -f *.c *.orig Makefile* Setup* sedscript )

do-install:
	${INSTALL_SCRIPT_DIR} ${PYTHON_LIBDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; ${PAX} -r -w -v -p p reportlab ${PYTHON_LIBDIR})
	(cd ${PREFIX}; ${FIND} ${SITE_PKG}/reportlab \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${SITE_PKG}/reportlab \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
