# $NetBSD: Makefile,v 1.2 2000/10/22 20:01:55 tsarna Exp $
#

DISTNAME=	ReportLab_1_01
PKGNAME=	py-reportlab-1.01
CATEGORIES=	print
MASTER_SITES=   ftp://ftp.reportlab.com/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.reportlab.com/

WRKSRC=		${WRKDIR}/reportlab/lib

ALL_TARGET=	default
PLIST_SRC=      ${WRKDIR}/.PLIST_SRC

do-configure:
	(cd ${WRKSRC} ;\
	  ${CP} ${PY_CONFIGDIR}/Makefile.pre.in . ;\
	  ${MAKE} -f Makefile.pre.in boot)

post-build:
	(cd ${WRKDIR}; \
	${PY_PROG} ${PY_LIBDIR}/compileall.py . ; \
	${PY_PROG} -O ${PY_LIBDIR}/compileall.py . )
	(cd ${WRKSRC}; \
	${MAKE} clean; ${RM} -f *.c *.orig Makefile* Setup* sedscript )

do-install:
	${INSTALL_SCRIPT_DIR} ${PY_LIBDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKDIR}; ${PAX} -r -w -v -p p reportlab ${PY_SITEPKG})
	(cd ${PREFIX}; ${FIND} ${PY_SITEPATH}/reportlab \
		-type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${PY_SITEPATH}/reportlab \
		-type d -print | ${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../lang/python/Makefile.inc"
.include "../../mk/bsd.pkg.mk"

