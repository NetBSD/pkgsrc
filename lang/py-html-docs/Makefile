# $NetBSD: Makefile,v 1.7 2000/01/02 04:22:31 tsarna Exp $
#

DISTNAME=	html-1.5.2
PKGNAME=	py-html-docs-1.5.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/doc/1.5.2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/

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
