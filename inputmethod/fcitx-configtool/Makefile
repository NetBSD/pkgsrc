# $NetBSD: Makefile,v 1.25 2026/01/27 08:39:54 wiz Exp $

DISTNAME=	fcitx-configtool-0.4.9
PKGREVISION=	22
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx-configtool/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://download.fcitx-im.org/fcitx-configtool/
COMMENT=	GTK 3 Fcitx configuration tool
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
