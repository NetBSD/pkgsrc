# $NetBSD: Makefile,v 1.11 2009/07/08 12:16:45 reed Exp $

PKGNAME=		py-twisted-docs-${TWISTED_VERSION}
COMMENT=		Framework for writing networked applications (documentation)
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
