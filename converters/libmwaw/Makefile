# $NetBSD: Makefile,v 1.3 2014/02/02 07:25:39 ryoon Exp $

DISTNAME=	libmwaw-0.2.0
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmwaw/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://sourceforge.net/p/libmwaw/wiki/Home/
COMMENT=	Import library for pre-OSX Mac text formats
LICENSE=	mpl-2.0 OR gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

CONFIGURE_ARGS+=	--without-docs

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--with-sharedptr=c++11
.else
CONFIGURE_ARGS+=	--with-sharedptr=tr1
.endif

PKGCONFIG_OVERRIDE+=	libmwaw.pc.in

.include "../../converters/libwpg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
