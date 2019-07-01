# $NetBSD: Makefile,v 1.23 2019/07/01 04:07:51 ryoon Exp $

DISTNAME=		clucene-core-2.3.3.4
PKGNAME=		lib${DISTNAME:S/-core-/-/}
PKGREVISION=		14
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=clucene/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://clucene.sourceforge.net/index.php/Main_Page
COMMENT=		Text search engine written in C++
LICENSE=		gnu-lgpl-v2.1 OR apache-2.0

PKGCONFIG_OVERRIDE+=	libclucene-core.pc.in

USE_LANGUAGES=		c c++
USE_CMAKE=		yes
CMAKE_ARGS+=		-DBUILD_CONTRIBS_LIB=ON
#BUILD_TARGET+=	clucene-contribs-lib
USE_LIBTOOL=		yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
