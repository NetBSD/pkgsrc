# $NetBSD: Makefile,v 1.8 1998/11/12 23:03:40 frueauf Exp $
#

DISTNAME=	libg++-${GXXVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tv@netbsd.org

LIB_DEPENDS=	stdc++.1.:	# only from NetBSD's source tree

BROKEN=		"Designed for NetBSD 1.4 - 1.3(.x) comes with this in-tree"

GXXVERSION=	2.8.1.1a	# used by internal Makefile

MAKE_ENV+=	GXXVERSION="${GXXVERSION}"
PLIST_SRC=	${WRKSRC}/.PLIST

INFO_FILES=	libg++.info

do-configure:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${MKDIR} ${PREFIX}/include/g++/gen

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genclass ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/libg++.info ${PREFIX}/info/
	@(${CAT} ${PKGDIR}/PLIST.pre; cd ${PREFIX}; \
		/bin/ls 2>/dev/null -1d lib/libg++*.a lib/libg++.so*) \
		>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
