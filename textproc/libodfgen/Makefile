# $NetBSD: Makefile,v 1.3 2014/02/02 09:48:31 ryoon Exp $

DISTNAME=	libodfgen-0.0.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/libodfgen/libodfgen-${PKGVERSION}/}

EXTRACT_SUFX=	.tar.xz

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library to generate ODF documents through libwpd and libwps
LICENSE=	mpl-2.0 OR gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--without-docs

PKGCONFIG_OVERRIDE+=	libodfgen.pc.in

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ARGS+=	--with-sharedptr=c++11
.else
CONFIGURE_ARGS+=	--with-sharedptr=tr1
.endif

.include "../../converters/libetonyek/buildlink3.mk"
.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
