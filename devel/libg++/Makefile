# $NetBSD: Makefile,v 1.12 1999/04/30 15:51:38 tv Exp $
#

DISTNAME=	libg++-${GXXVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=libg++/}

MAINTAINER=	tv@netbsd.org

.if !exists(/usr/lib/libstdc++.so.2.0)
IGNORE=		"Designed for NetBSD 1.4 - 1.3(.x) comes with this in-tree"
.endif

GXXVERSION=	2.8.1.1a	# used by internal Makefile

MAKE_ENV+=	GXXVERSION="${GXXVERSION}" NOPROFILE=1 NOGCCERROR=1
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
