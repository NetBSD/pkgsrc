# $NetBSD: Makefile,v 1.21 2009/06/14 18:16:33 joerg Exp $
#

DISTNAME=		geda-docs-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		HTML documentation for gEDA

DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols
BUILD_DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		find

PLIST_SRC=		${WRKDIR}/PLIST

# The docs are a snapshot of the wiki and each time around this is substantially different
# which makes maintaining the PLIST a bit of a pain.  So, automatically generate this
# portion of the PLIST.
post-install:
	${CAT} ${.CURDIR}/PLIST.pre > ${PLIST_SRC}
	${FIND} ${PREFIX}/share/doc/geda-doc/wiki -type f -print | \
		${SORT} | ${SED} 's;^${PREFIX}/;;g' >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
