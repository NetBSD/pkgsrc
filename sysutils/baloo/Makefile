# $NetBSD: Makefile,v 1.5 2016/03/23 15:40:36 jperkin Exp $

DISTNAME=	baloo-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	sysutils
COMMENT=	KDE framework for searching and managing user metadata
LICENSE=	gnu-gpl-v3

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_TOOLS+=	gmake

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	polkit
.if ${OPSYS} != "Darwin"
PLIST.polkit=	yes
.endif

.include "../../devel/qjson/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/kfilemetadata/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
