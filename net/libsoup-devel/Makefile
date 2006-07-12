# $NetBSD: Makefile,v 1.21 2006/07/12 13:51:34 wiz Exp $

DISTNAME=	libsoup-2.2.95.1
PKGNAME=	${DISTNAME:S/soup/soup-devel/}
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsoup/2.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	HTTP library implementation in C

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gtk-doc=no

PKGCONFIG_OVERRIDE+=    libsoup-2.2.pc.in

CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
