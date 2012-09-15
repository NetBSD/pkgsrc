# $NetBSD: Makefile,v 1.12 2012/09/15 10:04:08 obache Exp $
#

DISTNAME=	ethos-0.2.2
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	http://ftp.dronelabs.com/sources/ethos/0.2/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://git.dronelabs.com/ethos/about/
COMMENT=	Plugin interface library
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt

PKGCONFIG_OVERRIDE+=	ethos-ui.pc.in
PKGCONFIG_OVERRIDE+=	ethos.pc.in

TEST_TARGET=	check

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
