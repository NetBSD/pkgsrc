# $NetBSD: Makefile,v 1.36 2012/03/03 00:11:57 wiz Exp $

DISTNAME=	loudmouth-1.4.3
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/1.4/}

EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.loudmouth-project.org/
COMMENT=	Lightweight Jabber client library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-mono
CONFIGURE_ARGS+=	--with-ssl=openssl

PKGCONFIG_OVERRIDE+=	loudmouth-1.0.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
