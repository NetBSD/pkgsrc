# $NetBSD: Makefile,v 1.17 2012/10/31 11:19:45 asau Exp $

DISTNAME=		stl
PKGNAME=		sgi-stl-3.3
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/tech/stl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sgi.com/tech/stl/
COMMENT=		SGI Standard Template Library

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}

NO_CONFIGURE=		yes
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/sgi-stl
	cd ${WRKSRC}; for file in `${GREP} "^include/sgi-stl/" ${PLIST_SRC} \
	    | ${SED} "s,^include/sgi-stl/,,g"`; do \
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/include/sgi-stl/$${file}; \
	done

.include "../../mk/bsd.pkg.mk"
