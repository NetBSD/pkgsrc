# $NetBSD: Makefile,v 1.1 2026/11/14 07:23:20 wiz Exp $

DISTNAME=	yoshimi-2.3.6.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yoshimi/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Yoshimi/yoshimi/
COMMENT=	Software audio synthesizer
LICENSE=	gnu-gpl-v2

CONFIGURE_DIR=	src
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++ c

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/argp/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../audio/lv2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../textproc/mxml/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
