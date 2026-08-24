# $NetBSD: Makefile,v 1.47 2026/08/24 08:42:30 adam Exp $

DISTNAME=		clucene-core-2.3.3.4
PKGNAME=		lib${DISTNAME:S/-core-/-/}
PKGREVISION=		30
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clucene/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://clucene.sourceforge.net/index.php/Main_Page
COMMENT=		Text search engine written in C++
LICENSE=		gnu-lgpl-v2.1 OR apache-2.0

PKGCONFIG_OVERRIDE+=	libclucene-core.pc.in

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CMAKE_CONFIGURE_ARGS+=	-DBUILD_CONTRIBS_LIB=ON
# https://sourceforge.net/p/clucene/bugs/236/
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
