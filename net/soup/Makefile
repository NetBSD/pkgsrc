# $NetBSD: Makefile,v 1.17 2004/04/25 20:04:54 snj Exp $
#

DISTNAME=		soup-0.7.10
PKGREVISION=		8
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/soup/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Callback-based mechanism for sending and servicing SOAP requests

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	soup.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml/buildlink3.mk"
.include "../../devel/bonobo/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
