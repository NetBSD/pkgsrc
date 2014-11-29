# $NetBSD: Makefile,v 1.2 2014/11/29 00:44:49 joerg Exp $

DISTNAME=	librevenge-0.0.1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/libwpd/
COMMENT=	Base library for writing document import filters
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
# needs doxygen (heavy dependency); in case someone is interested
# in this, make it a package option
CONFIGURE_ARGS+=	--without-docs
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c++

PKGCONFIG_OVERRIDE+=	librevenge-generators.pc.in
PKGCONFIG_OVERRIDE+=	librevenge-stream.pc.in
PKGCONFIG_OVERRIDE+=	librevenge.pc.in

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CWRAPPERS_APPEND.cxx+=	-Wno-error=unused-local-typedef \
			-Wno-error=unused-parameter \
			-Wno-error=shadow
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
