# $NetBSD: Makefile,v 1.9 2022/06/30 11:18:36 nia Exp $

DISTNAME=		djbsort-20190516
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://sorting.cr.yp.to/
COMMENT=		Library for sorting arrays of integers
LICENSE=		public-domain

USE_TOOLS+=		pax

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON=		build test upgrade verif/decompose \
			verif/minmax verif/tryinput verif/unroll
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

post-build:
	${CP} pseudo-PLIST ${WRKSRC}
	cd ${WRKSRC} && ${FIND} . -type f | ${SORT} | ${SED} -e 's|^\.|${SHAREDIR}|g' > ${WRKDIR}/PLIST_DYNAMIC

do-install:
	cd ${WRKSRC} && pax -rw -pp -v . ${DESTDIR}${PREFIX}/${SHAREDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
