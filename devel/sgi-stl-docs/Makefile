# $NetBSD: Makefile,v 1.2 2000/07/13 16:38:01 jlam Exp $

DISTNAME=		STL_doc
PKGNAME=		sgi-stl-docs-3.3
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
