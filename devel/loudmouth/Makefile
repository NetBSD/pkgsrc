# $NetBSD: Makefile,v 1.4 2003/10/18 08:15:37 jmmv Exp $
#

DISTNAME=	loudmouth-0.14
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/0.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.imendio.com/projects/loudmouth/
COMMENT=	Lightweight Jabber client library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/loudmouth-1.0.pc.in

CONFIGURE_ARGS+=	--disable-debug

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	LOUDMOUTH_USE_SSL

.if defined(LOUDMOUTH_USE_SSL) && !empty(LOUDMOUTH_USE_SSL:M[Yy][Ee][Ss])
.include "../../security/gnutls/buildlink2.mk"
.else
CONFIGURE_ARGS+=	--with-ssl=no
.endif

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
