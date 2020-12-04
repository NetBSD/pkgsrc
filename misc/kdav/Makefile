# $NetBSD: Makefile,v 1.12 2020/12/04 04:56:03 riastradh Exp $

DISTNAME=	kdav-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	misc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	DAV protocol implemention with KJobs
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
