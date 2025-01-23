# $NetBSD: Makefile,v 1.25 2025/01/23 23:27:27 riastradh Exp $

DISTNAME=	fcitx5-m17n-5.1.0
PKGREVISION=	6
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-m17n/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-m17n
COMMENT=	Wrapper library of m17n for Fcitx5
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../devel/cmake/build.mk"

.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/m17n-lib/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
