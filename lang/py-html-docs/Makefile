# $NetBSD: Makefile,v 1.2 1998/08/20 15:17:08 tsarna Exp $
#

DISTNAME=	html-1.5.1
PKGNAME=	py-html-docs-1.5.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.python.org/pub/python/doc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.python.org/doc/

EXTRACT_ONLY=
NO_CONFIGURE=	yes
NO_BUILD=	yes

HTMLDIR=	share/doc/python-html
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	(cd ${PREFIX}/${HTMLDIR}; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${EXTRACT_AFTER_ARGS})
	(cd ${PREFIX}; find ${HTMLDIR} -type f -print >>${PLIST_SRC})
	(cd ${PREFIX}; find -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC})

.include "../../mk/bsd.pkg.mk"
