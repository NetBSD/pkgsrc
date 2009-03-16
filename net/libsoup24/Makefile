# $NetBSD: Makefile,v 1.8 2009/03/16 12:49:02 jmcneill Exp $

DISTNAME=	libsoup-2.25.91
PKGNAME=	${DISTNAME:S/libsoup/libsoup24/}
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsoup/2.25/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	HTTP library implementation in C

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libsoup-2.4.pc.in
PKGCONFIG_OVERRIDE+=	libsoup-gnome-2.4.pc.in

.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
