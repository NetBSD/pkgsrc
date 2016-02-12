# $NetBSD: Makefile,v 1.1 2016/02/12 13:34:45 wiz Exp $

DISTNAME=	mdds_0.12.1
PKGNAME=	${DISTNAME:S/_/0.12-/}
CATEGORIES=	devel
MASTER_SITES=	http://kohei.us/files/mdds/src/
EXTRACT_SUFX=	.tar.bz2
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/multidimalgorithm/
COMMENT=	Collection of multi-dimensional data structure and indexing algorithms (0.12 branch)
LICENSE=	mit

USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
#NO_BUILD=		yes
INSTALLATION_DIRS=	include/mdds/compat include/mdds/hash_container \
			share/pkgconfig
PKGCONFIG_OVERRIDE+=	misc/mdds.pc.in

do-install:
	for i in ${WRKSRC}/include/mdds/*.hpp; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/include/mdds; \
	done
	for i in ${WRKSRC}/include/mdds/*.inl; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/include/mdds; \
	done
	for i in ${WRKSRC}/include/mdds/compat/*.hpp; do \
		${INSTALL_DATA} $$i ${DESTDIR}${PREFIX}/include/mdds/compat; \
	done
	for i in ${WRKSRC}/include/mdds/hash_container/*.hpp; do \
		${INSTALL_DATA} $$i \
			${DESTDIR}${PREFIX}/include/mdds/hash_container; \
	done
	${INSTALL_DATA} ${WRKSRC}/misc/mdds.pc ${DESTDIR}${PREFIX}/share/pkgconfig

BUILDLINK_DEPMETHOD.boost-headers?=	build
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
