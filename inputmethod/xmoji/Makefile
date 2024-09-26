# $NetBSD: Makefile,v 1.3 2024/09/26 21:05:20 wiz Exp $

DISTNAME=	xmoji-0.8
CATEGORIES=	inputmethod x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=Zirias/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Zirias/xmoji/
COMMENT=	Plain X11 emoji keyboard
LICENSE=	2-clause-bsd

MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	SH=${CONFIG_SHELL}

USE_TOOLS+=	gmake pkg-config

USE_CC_FEATURES+=	c11
# pkgsrc passes in its own LDFLAGS, and this part is lost (as of 0.7)
LDFLAGS+=		-L$$(LIBDIR)

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxcb+=	libxcb>=1.14
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
