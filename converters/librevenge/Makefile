# $NetBSD: Makefile,v 1.6 2015/10/07 09:30:19 fhajny Exp $

DISTNAME=	librevenge-0.0.2
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libwpd/
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

LIBS+=	-lboost_system

PTHREAD_AUTO_VARS=	yes

#.include "../../mk/compiler.mk"
#.if !empty(PKGSRC_COMPILER:Mclang)
#CWRAPPERS_APPEND.cxx+=	-Wno-error=unused-local-typedef \
#			-Wno-error=unused-parameter \
#			-Wno-error=shadow
#.endif

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
