# $NetBSD: Makefile,v 1.21 2014/02/25 12:37:26 ryoon Exp $
#

DISTNAME=	47203e7cade74e5c385aa812f21e7932-mdds_0.10.2
PKGNAME=	${DISTNAME:C/[0-9a-f]*-//:S/_/-/}
CATEGORIES=	devel
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.bz2
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/multidimalgorithm/
COMMENT=	Collection of multi-dimensional data structure and indexing algorithms
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME:C/[0-9a-f]*-//}

USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
NO_BUILD=		yes
INSTALLATION_DIRS=	include/mdds/compat include/mdds/hash_container \
			share/pkgconfig
PKGCONFIG_OVERRIDE+=	misc/mdds.pc.in

do-install:
	for i in ${WRKSRC}/include/mdds/*.*; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/include/mdds; \
	done
	for i in ${WRKSRC}/include/mdds/compat/*.*; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/include/mdds/compat; \
	done
	rm -f ${DESTDIR}${PREFIX}/include/mdds/*orig
	for i in ${WRKSRC}/include/mdds/hash_container/*.*; do \
		${INSTALL_DATA} $$i \
			${DESTDIR}${PREFIX}/include/mdds/hash_container; \
	done
	${INSTALL_DATA} ${WRKSRC}/misc/mdds.pc ${DESTDIR}${PREFIX}/share/pkgconfig

BUILDLINK_DEPMETHOD.boost-headers?=	build
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
