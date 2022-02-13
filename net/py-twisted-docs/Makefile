# $NetBSD: Makefile,v 1.19 2022/02/13 08:53:44 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-install:
	cd ${DOC_SRCDIR} && pax -rw -pp * ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
