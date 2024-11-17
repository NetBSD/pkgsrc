# $NetBSD: Makefile,v 1.3 2024/11/17 07:16:40 wiz Exp $

DISTNAME=	libayatana-indicator-0.9.4
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=AyatanaIndicators/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AyatanaIndicators/libayatana-indicator/
COMMENT=	Ayatana Indicators Shared Library
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	data/ayatana-indicator.pc.in
PKGCONFIG_OVERRIDE+=	data/ayatana-indicator3-no-IDO.pc.in
PKGCONFIG_OVERRIDE+=	data/ayatana-indicator3.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/ayatana-ido/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
