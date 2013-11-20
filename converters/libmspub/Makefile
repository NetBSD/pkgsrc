# $NetBSD: Makefile,v 1.5 2013/11/20 20:04:36 adam Exp $

DISTNAME=	libmspub-0.0.6
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	http://dev-www.libreoffice.org/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/libmspub
COMMENT=	Library for importing Microsoft Publisher content
LICENSE=	mpl-1.1 OR gnu-lgpl-v2 OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++
CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libmspub.pc.in

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-error=unknown-pragmas -Wno-error=c++11-extensions
.endif

.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
