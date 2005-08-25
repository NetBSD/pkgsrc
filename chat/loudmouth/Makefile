# $NetBSD: Makefile,v 1.15 2005/08/25 20:16:15 jmmv Exp $

DISTNAME=	loudmouth-1.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/1.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://loudmouth.imendio.org/
COMMENT=	Lightweight Jabber client library

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    loudmouth-1.0.pc.in

CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-mono

BUILDLINK_DEPENDS.gnutls+=	gnutls>=1.2.0

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
