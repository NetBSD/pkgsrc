# $NetBSD: Makefile,v 1.4 2001/05/31 10:27:50 dent Exp $

DISTNAME=		stl
PKGNAME=		sgi-stl-3.3
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/tech/stl/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.sgi.com/tech/stl/
COMMENT=		SGI Standard Template Library

DIST_SUBDIR=		${PKGNAME}
NO_WRKSUBDIR=		# defined

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/sgi-stl
	cd ${WRKSRC}; for file in `${GREP} "^include/sgi-stl/" ${PLIST_SRC} \
	    | ${SED} "s,^include/sgi-stl/,,g"`; do \
		${INSTALL_DATA} $${file} ${PREFIX}/include/sgi-stl/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
