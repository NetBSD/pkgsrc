# $NetBSD: Makefile,v 1.8 2000/10/22 20:01:50 tsarna Exp $
#

DISTNAME=	html-2.0
PKGNAME=	py-html-docs-2.0
CATEGORIES=	lang
MASTER_SITES=	http://www.python.org/ftp/python/doc/2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/

DIST_SUBDIR=	python

NO_WRKSUBDIR=	yes

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python-html
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}; ${PAX} -r -w -v -p e [a-z]* ${PREFIX}/${HTMLDIR})
	(cd ${PREFIX}; ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
