# $NetBSD: Makefile,v 1.3 2010/09/23 08:26:09 obache Exp $
#

DISTNAME=	libgee-0.5.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgee/0.5/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Libgee
COMMENT=	Library providing GObject-based interfaces and classes
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	gee-1.0.pc.in

TEST_TARGET=	check

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
