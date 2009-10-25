# $NetBSD: Makefile,v 1.1.1.1 2009/10/25 23:39:01 joerg Exp $
#

VERS=		2.6.3
DISTNAME=	python-${VERS}-docs-html
PKGNAME=	py26-html-docs-${VERS}
CATEGORIES=	lang python
MASTER_SITES=	http://docs.python.org/ftp/python/doc/current/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/
COMMENT=	HTML Documentation for Python

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	python

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/html/python2.6
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	cd ${WRKSRC} && pax -rw -pe [a-z]* ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
