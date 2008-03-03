# $NetBSD: Makefile,v 1.16 2008/03/03 17:45:37 jlam Exp $

DISTNAME=		stl
PKGNAME=		sgi-stl-3.3
CATEGORIES=		devel
MASTER_SITES=		http://www.sgi.com/tech/stl/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.sgi.com/tech/stl/
COMMENT=		SGI Standard Template Library

PKG_DESTDIR_SUPPORT=	user-destdir

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
