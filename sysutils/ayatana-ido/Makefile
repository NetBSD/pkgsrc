# $NetBSD: Makefile,v 1.1 2024/05/25 01:32:29 gutteridge Exp $

DISTNAME=	ayatana-ido-0.10.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=AyatanaIndicators/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AyatanaIndicators/ayatana-ido/
COMMENT=	Ayatana Indicator Display Objects
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3 AND gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	data/libayatana-ido3-0.4.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
