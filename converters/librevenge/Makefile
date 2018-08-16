# $NetBSD: Makefile,v 1.17 2018/08/16 18:54:27 adam Exp $

DISTNAME=	librevenge-0.0.4
PKGREVISION=	7
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/libwpd/
COMMENT=	Base library for writing document import filters
LICENSE=	mpl-2.0

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
# Do not use -Werror, or configure will fail.
CONFIGURE_ARGS+=	--disable-werror
# needs doxygen (heavy dependency); in case someone is interested
# in this, make it a package option
CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	librevenge-generators.pc.in
PKGCONFIG_OVERRIDE+=	librevenge-stream.pc.in
PKGCONFIG_OVERRIDE+=	librevenge.pc.in

PTHREAD_AUTO_VARS=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
