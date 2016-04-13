# $NetBSD: Makefile,v 1.18 2016/04/13 19:45:38 wiz Exp $

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
	cd ${DOC_SRCDIR} && pax -rw -pp * ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
