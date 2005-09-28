# $NetBSD: Makefile,v 1.5 2005/09/28 20:52:25 rillig Exp $
#

DISTNAME=		${TWISTED_DISTNAME}
PKGNAME=		py-twisted-docs-${TWISTED_VERSION}
CATEGORIES=		net python
MASTER_SITES=		${TWISTED_MASTER_SITES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Framework for writing networked applications

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=

HTMLDIR=	share/doc/py-twisted-docs-${TWISTED_VERSION}
DOC_SRCDIR=	${WRKSRC}/doc
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && ${PAX} -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../net/py-twisted/Makefile.common"
.include "../../mk/bsd.pkg.mk"
