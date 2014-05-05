# $NetBSD: Makefile,v 1.26 2014/05/05 00:48:08 ryoon Exp $
#

DISTNAME=	gelemental-1.2.0
PKGREVISION=	21
CATEGORIES=	misc
MASTER_SITES=	http://www.kdau.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kdau.com/projects/gelemental/
COMMENT=	Periodic table viewer

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	data/libelemental.pc.in

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
