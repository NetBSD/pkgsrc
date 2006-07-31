# $NetBSD: Makefile,v 1.23 2006/07/31 09:11:46 adam Exp $

DISTNAME=	loudmouth-1.0.4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://loudmouth.imendio.org/
COMMENT=	Lightweight Jabber client library

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-mono

PKGCONFIG_OVERRIDE+=	loudmouth-1.0.pc.in

BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=1.2.0

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
