# $NetBSD: Makefile,v 1.5 2003/07/17 21:33:58 grant Exp $

DISTNAME=		STL_doc
PKGNAME=		sgi-stl-docs-3.3
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/tech/stl/

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.sgi.com/tech/stl/
COMMENT=		SGI Standard Template Library Programmer's Guide

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
