# $NetBSD: Makefile,v 1.15 2004/02/14 18:26:28 jmmv Exp $
#

DISTNAME=		soup-0.7.10
PKGREVISION=		7
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/soup/0.7/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Callback-based mechanism for sending and servicing SOAP requests

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	soup.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no

.include "../../converters/libiconv/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../devel/bonobo/buildlink2.mk"
.include "../../devel/GConf/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
