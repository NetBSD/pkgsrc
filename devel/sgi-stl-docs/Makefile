# $NetBSD: Makefile,v 1.1.1.1 2000/05/24 05:51:05 jlam Exp $

DISTNAME=		STL_doc
PKGNAME=		sgi-stl-docs-3.2
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/Technology/STL/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.sgi.com/Technology/STL/

DIST_SUBDIR=		${PKGNAME}

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

HTMLDOCDIR=		share/doc/html/sgi-stl

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDOCDIR}
	cd ${WRKSRC}; for file in `${GREP} "^${HTMLDOCDIR}/" ${PLIST_SRC} \
	    | ${SED} "s,^${HTMLDOCDIR}/,,g"`; do \
		${INSTALL_DATA} $${file} ${PREFIX}/${HTMLDOCDIR}/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
