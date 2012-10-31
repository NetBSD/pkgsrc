# $NetBSD: Makefile,v 1.12 2012/10/31 11:19:46 asau Exp $

DISTNAME=		STL_doc
PKGNAME=		sgi-stl-docs-3.3
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/tech/stl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sgi.com/tech/stl/
COMMENT=		SGI Standard Template Library Programmer's Guide

DIST_SUBDIR=		${PKGNAME_NOREV}

NO_CONFIGURE=		yes
NO_BUILD=		yes

HTMLDOCDIR=		share/doc/sgi-stl/html

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${HTMLDOCDIR}
	cd ${WRKSRC}; for file in `${GREP} "^${HTMLDOCDIR}/" ${PLIST_SRC} \
	    | ${SED} "s,^${HTMLDOCDIR}/,,g"`; do \
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/${HTMLDOCDIR}/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
