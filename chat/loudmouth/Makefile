# $NetBSD: Makefile,v 1.1.1.1 2004/02/20 14:16:18 jmmv Exp $
#

DISTNAME=	loudmouth-0.15.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/0.15/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://loudmouth.imendio.org/
COMMENT=	Lightweight Jabber client library

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

PKGCONFIG_OVERRIDE+=    loudmouth-1.0.pc.in

CONFIGURE_ARGS+=	--disable-debug

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	LOUDMOUTH_USE_SSL

.if defined(LOUDMOUTH_USE_SSL) && !empty(LOUDMOUTH_USE_SSL:M[Yy][Ee][Ss])
BUILDLINK_DEPENDS.gnutls=	gnutls>=1.0.0
.include "../../security/gnutls/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--with-ssl=no
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
