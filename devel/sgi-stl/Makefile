# $NetBSD: Makefile,v 1.1.1.1 2000/05/24 05:46:52 jlam Exp $

DISTNAME=		stl
PKGNAME=		sgi-stl-3.2
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/Technology/STL/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.sgi.com/Technology/STL/

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
