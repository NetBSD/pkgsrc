# $NetBSD: Makefile,v 1.7 2004/01/23 09:45:51 xtraeme Exp $
#

DISTNAME=	loudmouth-0.15.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/0.15/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://loudmouth.imendio.org/
COMMENT=	Lightweight Jabber client library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/loudmouth-1.0.pc.in

CONFIGURE_ARGS+=	--disable-debug

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	LOUDMOUTH_USE_SSL

.if defined(LOUDMOUTH_USE_SSL) && !empty(LOUDMOUTH_USE_SSL:M[Yy][Ee][Ss])
BUILDLINK_DEPENDS.gnutls=	gnutls>=1.0.0
.include "../../security/gnutls/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--with-ssl=no
.endif

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
