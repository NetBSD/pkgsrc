# $NetBSD: Makefile,v 1.23 2020/05/28 15:33:29 rillig Exp $

DISTNAME=	libkgapi-2.2.0
PKGREVISION=	20
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=libkgapi/2.2.0/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE-based library for accessing various Google services
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
TOOLS_BROKEN+=	perl


.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/qjson/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
