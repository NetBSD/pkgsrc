# $NetBSD: Makefile,v 1.6 2019/04/25 07:33:05 maya Exp $

DISTNAME=		djbsort-20180729
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://sorting.cr.yp.to/
COMMENT=		Library for sorting arrays of integers
LICENSE=		public-domain

DEPENDS+=		python27-[0-9]*:../../lang/python27

USE_TOOLS+=		pax

REPLACE_INTERPRETER+=	python27
REPLACE.python27.old=	.*python2\{0,1\}[^ ]*
REPLACE.python27.new=	${LOCALBASE}/bin/python2.7
REPLACE_FILES.python27=	verif/decompose verif/minmax verif/unroll

PYTHON_VERSIONS_INCOMPATIBLE=	27	# so a python3 will be auto-selected

REPLACE_PYTHON=		build test upgrade verif/tryinput
SUBST_CLASSES+=		python3
SUBST_STAGE.python3=	do-configure
SUBST_FILES.python3=	verif/verifymany
SUBST_SED.python3=	-e 's|time python3|time ${PYTHONBIN}|g'

SHAREDIR=		share/${PKGBASE}
FILES_SUBST+=		DIFF=${DIFF:Q}
FILES_SUBST+=		INSTALL_DATA=${INSTALL_DATA:Q}
FILES_SUBST+=		PSEUDO_PLIST=${PSEUDO_PLIST:Q}
FILES_SUBST+=		SHAREDIR=${SHAREDIR:Q}

INSTALLATION_DIRS=	include lib ${SHAREDIR}

PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

pre-configure:
	cd ${WRKSRC} && rm -f *.orig

do-build:
	cd ${WRKSRC} && ./build

pre-install:
	${CP} pseudo-PLIST ${WRKSRC}
	cd ${WRKSRC} && ${FIND} . -type f | ${SORT} | ${SED} -e 's|^\.|${SHAREDIR}|g' > ${WRKDIR}/PLIST_DYNAMIC

do-install:
	cd ${WRKSRC} && pax -rw -pe -v . ${DESTDIR}${PREFIX}/${SHAREDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
