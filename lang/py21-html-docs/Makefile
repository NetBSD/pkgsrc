# $NetBSD: Makefile,v 1.1.1.1 2002/04/19 10:48:34 drochner Exp $
#

DISTNAME=	html-2.1.3
PKGNAME=	py21-html-docs-2.1.3
CATEGORIES=	lang
MASTER_SITES=	http://www.python.org/ftp/python/doc/2.1.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/
COMMENT=	HTML Documentation for Python

DIST_SUBDIR=	python

WRKSRC=		${WRKDIR}

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/html/python2.1
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}; ${PAX} -r -w -v -p e [a-z]* ${PREFIX}/${HTMLDIR})
	(cd ${PREFIX}; ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
