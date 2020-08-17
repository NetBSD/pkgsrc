# $NetBSD: Makefile,v 1.27 2020/08/17 20:20:02 leot Exp $

DISTNAME=	baloo-widgets-${_KDE_VERSION}
PKGREVISION=	25
CATEGORIES=	sysutils
COMMENT=	The BalooWidgets library
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde4/Makefile.kde4"

#USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde4/kde4.mk"

#.include "../../devel/qjson/buildlink3.mk"
#.include "../../mail/akonadi/buildlink3.mk"
#.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/libbaloo4/buildlink3.mk"
.include "../../sysutils/kfilemetadata/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
