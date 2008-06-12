# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:42 joerg Exp $
#

DISTNAME=		${TWISTED_DISTNAME}
PKGNAME=		py-twisted-docs-${TWISTED_VERSION}
CATEGORIES=		net python
MASTER_SITES=		${TWISTED_MASTER_SITES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.twistedmatrix.com/
COMMENT=		Framework for writing networked applications

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# empty
USE_TOOLS+=	pax

HTMLDIR=	share/doc/py-twisted-docs-${TWISTED_VERSION}
DOC_SRCDIR=	${WRKSRC}/doc
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && pax -rw -pe * ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${DESTDIR}${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../net/py-twisted/Makefile.common"
.include "../../mk/bsd.pkg.mk"
