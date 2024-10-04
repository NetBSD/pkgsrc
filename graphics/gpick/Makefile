# $NetBSD: Makefile,v 1.48 2024/10/04 04:17:37 ryoon Exp $

DISTNAME=	gpick-0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=thezbyg/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/thezbyg/gpick/
COMMENT=	Advanced color picker
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt msgmerge xgettext

USE_CXX_FEATURES+=	filesystem

TOOL_DEPENDS+=	ragel-[0-9]*:../../devel/ragel

CXXFLAGS+=	-Wno-sign-compare
LDFLAGS+=	-llua

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
