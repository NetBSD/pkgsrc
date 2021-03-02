# $NetBSD: Makefile,v 1.3 2021/03/02 03:04:22 mef Exp $

DISTNAME=	fcitx5-anthy-5.0.3
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-anthy/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-anthy
COMMENT=	Anthy Japanese inputmethod for Fcitx5
LICENSE=	gnu-gpl-v2

DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules/

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../inputmethod/anthy/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
