# $NetBSD: Makefile,v 1.3 1999/04/01 14:07:54 agc Exp $
#

DISTNAME=	html-1.5.1
PKGNAME=	py-html-docs-1.5.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/

NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python-html
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${WRKSRC}; pax -r -w -v -p -e . ${PREFIX}/${HTMLDIR})
	(cd ${PREFIX}; find ${HTMLDIR} -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; find -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
