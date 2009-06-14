# $NetBSD: Makefile,v 1.2 2009/06/14 22:58:03 joerg Exp $
#

DISTNAME=	html-2.5.2
PKGNAME=	${DISTNAME:S/html/py25-html-docs/}
CATEGORIES=	lang python
MASTER_SITES=	http://www.python.org/ftp/python/doc/2.5.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	smb@NetBSD.org
HOMEPAGE=	http://www.python.org/doc/
COMMENT=	HTML Documentation for Python

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Python-Docs-2.5.2/
DIST_SUBDIR=	python

USE_TOOLS+=	pax

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/html/python2.5
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

INSTALLATION_DIRS=	${HTMLDIR}

do-install:
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && pax -rw -pe [a-z]* ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
