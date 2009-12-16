# $NetBSD: Makefile,v 1.20 2009/12/16 19:02:26 drochner Exp $

DISTNAME=	libsoup-2.28.2
PKGNAME=	${DISTNAME:S/libsoup/libsoup24/}
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsoup/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	HTTP library implementation in C
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libsoup-2.4.pc.in
PKGCONFIG_OVERRIDE+=	libsoup-gnome-2.4.pc.in

TEST_TARGET=	check

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.21.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/gnome-keyring/buildlink3.mk"
BUILDLINK_API_DEPENDS.gnutls+=	gnutls>=2.1.7
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
