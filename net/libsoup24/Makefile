# $NetBSD: Makefile,v 1.33 2011/07/29 10:27:29 drochner Exp $

DISTNAME=	libsoup-2.34.2
PKGNAME=	${DISTNAME:S/libsoup/libsoup24/}
PKGREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsoup/2.34/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	HTTP library implementation in C
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DEPENDS+=	glib-networking-[0-9]*:../../net/glib-networking

PKGCONFIG_OVERRIDE+=	libsoup-2.4.pc.in

TEST_TARGET=	check

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.21.3
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libproxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
