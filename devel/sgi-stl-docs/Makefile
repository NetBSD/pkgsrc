# $NetBSD: Makefile,v 1.6 2004/04/24 22:46:09 jlam Exp $

DISTNAME=		STL_doc
PKGNAME=		sgi-stl-docs-3.3
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/tech/stl/

MAINTAINER=		tech-pkg@NetBSD.org
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
