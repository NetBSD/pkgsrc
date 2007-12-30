# $NetBSD: Makefile,v 1.2 2007/12/30 17:15:25 joerg Exp $
#

DISTNAME=	gelemental-1.2.0
CATEGORIES=	misc
MASTER_SITES=	http://www.kdau.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kdau.com/projects/gelemental/
COMMENT=	Periodic table viewer

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config intltool gmake msgfmt
USE_LANGUAGES=	c++
USE_DIRS+=	xdg-1.1

PKGCONFIG_OVERRIDE+=	data/libelemental.pc.in

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
