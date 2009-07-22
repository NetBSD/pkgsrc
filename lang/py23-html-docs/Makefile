# $NetBSD: Makefile,v 1.9 2009/07/22 09:28:15 wiz Exp $
#

DISTNAME=	html-2.3.3
PKGNAME=	py23-html-docs-2.3.3
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/ftp/python/doc/2.3.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/
COMMENT=	HTML Documentation for Python

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/Python-Docs-2.3.3/
DIST_SUBDIR=	python

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/html/python2.3
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${WRKSRC} && pax -rw -pe [a-z]* ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
