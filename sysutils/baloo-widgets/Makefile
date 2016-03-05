# $NetBSD: Makefile,v 1.6 2016/03/05 11:29:28 jperkin Exp $

DISTNAME=	baloo-widgets-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	sysutils
COMMENT=	The BalooWidgets library
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde4/Makefile.kde4"

#USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde4/kde4.mk"

#.include "../../devel/qjson/buildlink3.mk"
#.include "../../mail/akonadi/buildlink3.mk"
#.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/baloo/buildlink3.mk"
.include "../../sysutils/kfilemetadata/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
