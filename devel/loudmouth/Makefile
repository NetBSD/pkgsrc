# $NetBSD: Makefile,v 1.1.1.1 2003/09/02 07:27:58 xtraeme Exp $
#

DISTNAME=	loudmouth-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/${DIST_VER}/}
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

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--disable-debug

DIST_VER=		0.13
VERSION=		0.13.2

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	LOUDMOUTH_USE_SSL

.if defined(LOUDMOUTH_USE_SSL) && !empty(LOUDMOUTH_USE_SSL:M[Yy][Ee][Ss])
.include "../../security/gnutls/buildlink2.mk"
.endif

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
