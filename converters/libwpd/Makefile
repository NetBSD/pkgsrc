# $NetBSD: Makefile,v 1.20 2010/10/09 12:17:12 wiz Exp $

DISTNAME=	libwpd-0.8.14
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-docs
PKGCONFIG_OVERRIDE+=	libwpd-0.8.pc.in libwpd-stream-0.8.pc.in

.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
