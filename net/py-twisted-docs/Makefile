# $NetBSD: Makefile,v 1.1.1.1 2004/03/30 13:33:44 recht Exp $
#

DISTNAME=		${TWISTED_DISTNAME}
PKGNAME=		py-twisted-docs-${TWISTED_VERSION}
CATEGORIES=		net
MASTER_SITES=		${TWISTED_MASTER_SITES}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Framework for writing networked applications

NO_CONFIGURE=	# defined
NO_BUILD=	# defined
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

.include "../../wip/py-twisted/Makefile.common"
.include "../../mk/bsd.pkg.mk"
