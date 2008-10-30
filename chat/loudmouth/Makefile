# $NetBSD: Makefile,v 1.30 2008/10/30 22:07:25 wiz Exp $

DISTNAME=	loudmouth-1.4.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/1.4/} \
		http://ftp.imendio.com/pub/imendio/loudmouth/src/
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

PKGCONFIG_OVERRIDE+=	loudmouth-1.0.pc.in

BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=1.2.0

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
