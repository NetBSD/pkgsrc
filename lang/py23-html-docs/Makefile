# $NetBSD: Makefile,v 1.6 2008/03/04 16:38:12 jlam Exp $
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

WRKSRC=		${WRKDIR}/Python-Docs-2.3.3/
DIST_SUBDIR=	python

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/html/python2.3
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe [a-z]* ${DESTDIR}${PREFIX}/${HTMLDIR}
	cd ${DESTDIR}${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${DESTDIR}${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
