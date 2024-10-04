# $NetBSD: Makefile,v 1.31 2024/10/04 03:49:17 ryoon Exp $

DISTNAME=	librevenge-0.0.5
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/libwpd/
COMMENT=	Base library for writing document import filters
LICENSE=	mpl-2.0

USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
# Do not use -Werror, or configure will fail.
CONFIGURE_ARGS+=	--disable-werror
# needs doxygen (heavy dependency); in case someone is interested
# in this, make it a package option
CONFIGURE_ARGS+=	--without-docs
TEST_TARGET=		check

PKGCONFIG_OVERRIDE+=	librevenge-generators.pc.in
PKGCONFIG_OVERRIDE+=	librevenge-stream.pc.in
PKGCONFIG_OVERRIDE+=	librevenge.pc.in

PTHREAD_AUTO_VARS=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
