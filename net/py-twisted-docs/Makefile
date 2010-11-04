# $NetBSD: Makefile,v 1.12 2010/11/04 19:40:02 adam Exp $

PKGNAME=	py-twisted-docs-${TWISTED_VERSION}
COMMENT=	Framework for writing networked applications (documentation)
.include "../../net/py-twisted/Makefile.common"

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

HTMLDIR=	share/doc/py-twisted-docs
DOC_SRCDIR=	${WRKSRC}/doc
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${DOC_SRCDIR} && pax -rw -pe * ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
