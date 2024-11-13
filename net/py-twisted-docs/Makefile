# $NetBSD: Makefile,v 1.20 2024/11/13 09:11:39 adam Exp $

PKGNAME=	py-${DISTNAME:S/Twisted/twisted-docs/}
COMMENT=	Framework for writing networked applications (documentation)
.include "../../net/py-twisted/Makefile.common"

USE_TOOLS+=	pax
NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/py-twisted-docs
DOC_SRCDIR=	${WRKSRC}/docs
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${DOC_SRCDIR} && ${PAX} -rw -pp * ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
