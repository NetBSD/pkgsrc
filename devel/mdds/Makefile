# $NetBSD: Makefile,v 1.18 2013/11/20 13:23:42 obache Exp $
#

DISTNAME=	mdds_0.9.0
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://multidimalgorithm.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2
EXTRACT_USING=	gtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/multidimalgorithm/
COMMENT=	Collection of multi-dimensional data structure and indexing algorithms
LICENSE=	mit

USE_LANGUAGES=		c++
GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	include/mdds/hash_container share/pkgconfig
PKGCONFIG_OVERRIDE+=	misc/mdds.pc.in

do-build:

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
