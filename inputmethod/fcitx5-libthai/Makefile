# $NetBSD: Makefile,v 1.5 2023/06/06 12:41:38 riastradh Exp $

DISTNAME=	fcitx5-libthai-5.0.2
CATEGORIES=	inputmethod
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/fcitx5-libthai/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/fcitx/fcitx5-libthai
COMMENT=	Thai language input method for Fcitx5
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# NetBSD's iconv does not support th_TH.UTF-8.
USE_GNU_ICONV=		yes
.endif
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libthai/buildlink3.mk"
.include "../../inputmethod/fcitx5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
