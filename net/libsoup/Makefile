# $NetBSD: Makefile,v 1.1.1.1 2003/12/05 22:54:11 xtraeme Exp $
#

DISTNAME=		libsoup-1.99.26
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libsoup/1.99/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		HTTP library implementation in C

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/soup-2.0.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc

.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
