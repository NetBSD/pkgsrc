# $NetBSD: Makefile,v 1.1.1.1 2004/04/02 18:11:57 recht Exp $
#

DISTNAME=		libsoup-2.1.8
PKGNAME=		${DISTNAME:S/soup/soup-devel/}
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libsoup/2.1/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		HTTP library implementation in C (dev. Version)

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=    soup-2.2.pc.in

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
