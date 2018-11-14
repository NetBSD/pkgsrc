# $NetBSD: Makefile,v 1.4 2018/11/14 22:21:49 kleink Exp $

DISTNAME=	fcitx-configtool-0.4.9
PKGREVISION=	2
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

.include "../../inputmethod/fcitx/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
