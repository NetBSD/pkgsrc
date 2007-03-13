# $NetBSD: Makefile,v 1.1.1.1 2007/03/13 10:00:30 drochner Exp $
#

DISTNAME=	libkexiv2-0.1.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kipi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kipi.sourceforge.net/
COMMENT=	KDE wrapper for exiv2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	libkexiv2/libkexiv2.pc.in

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
