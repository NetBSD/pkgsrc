# $NetBSD: Makefile,v 1.1.1.1 2011/01/13 15:56:24 drochner Exp $
#

DISTNAME=	atkmm-2.22.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atkmm/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	C++ bindings for atk
#LICENSE=	# TODO: (see mk/license.mk)

CONFLICTS+=	gtkmm<2.22.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake perl
USE_LIBTOOL=	yes
USE_LANGUAGES=	c++
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	atkmm-2.22.1/atk/PaxHeaders.17805/atkmm.pc.in
PKGCONFIG_OVERRIDE+=	atkmm-2.22.1/atk/atkmm.pc.in

.include "../../devel/atk/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
