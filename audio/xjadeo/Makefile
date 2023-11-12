# $NetBSD: Makefile,v 1.22 2023/11/12 13:20:45 wiz Exp $

DISTNAME=	xjadeo-0.8.9
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=x42/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xjadeo.sourceforge.net/
COMMENT=	X JAck viDEo mOnitor
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=	automake aclocal autoheader autoconf pkg-config

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-ltc
CONFIGURE_ARGS+=	--disable-sdl

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../audio/jack/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
