# $NetBSD: Makefile,v 1.5 2004/05/07 01:14:47 xtraeme Exp $
#

DISTNAME=	loudmouth-0.15.1
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/loudmouth/0.15/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://loudmouth.imendio.org/
COMMENT=	Lightweight Jabber client library

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

PKGCONFIG_OVERRIDE+=    loudmouth-1.0.pc.in

CONFIGURE_ARGS+=	--disable-debug

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
