# $NetBSD: Makefile,v 1.3 1998/04/15 10:38:20 agc Exp $
#

GXXVERSION=	2.8.1.1a	# used by internal Makefile
DISTNAME=	libg++-${GXXVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tv@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
LIB_DEPENDS=	stdc++.1.:	# only from NetBSD's source tree

MAKE_ENV+=	GXXVERSION="${GXXVERSION}"
PLIST_SRC=	${WRKSRC}/.PLIST

MAN1=	gperf.1

do-configure:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

pre-install:
	${MKDIR} ${PREFIX}/include/g++/gen

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genclass ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/gperf ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/gperf.info ${WRKSRC}/libg++.info ${PREFIX}/info/
	@install-info ${PREFIX}/info/gperf.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/libg++.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${WRKSRC}/libg++/gperf/gperf.1 ${PREFIX}/man/man1/
	@(${CAT} ${PKGDIR}/PLIST.pre; cd ${PREFIX}; \
		/bin/ls 2>/dev/null -1d lib/libg++*.a lib/libg++.so*) \
		>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
