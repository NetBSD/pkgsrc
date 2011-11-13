# $NetBSD: Makefile,v 1.9 2011/11/13 16:13:08 gls Exp $
#

DISTNAME=	libgee-0.6.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgee/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Libgee
COMMENT=	Library providing GObject-based interfaces and classes
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		pkg-config gmake
BUILD_DEPENDS+=	vala-[0-9]*:../../lang/vala

PKGCONFIG_OVERRIDE+=	gee-1.0.pc.in

TEST_TARGET=	check

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
