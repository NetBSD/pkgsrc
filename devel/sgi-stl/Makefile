# $NetBSD: Makefile,v 1.11 2004/04/27 03:09:58 snj Exp $

DISTNAME=		stl
PKGNAME=		sgi-stl-3.3
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/tech/stl/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.sgi.com/tech/stl/
COMMENT=		SGI Standard Template Library

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME}

USE_BUILDLINK3=		yes
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/include/sgi-stl
	cd ${WRKSRC}; for file in `${GREP} "^include/sgi-stl/" ${PLIST_SRC} \
	    | ${SED} "s,^include/sgi-stl/,,g"`; do \
		${INSTALL_DATA} $${file} ${PREFIX}/include/sgi-stl/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
