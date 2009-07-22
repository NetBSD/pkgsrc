# $NetBSD: Makefile,v 1.20 2009/07/22 09:28:15 wiz Exp $
#

DISTNAME=	html-2.0
PKGNAME=	py-html-docs-2.0
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/ftp/python/doc/2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/
COMMENT=	HTML Documentation for Python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	python

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/html/python
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${WRKSRC} && pax -rw -pe [a-z]* ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
