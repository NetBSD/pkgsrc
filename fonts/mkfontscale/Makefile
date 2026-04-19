# $NetBSD: Makefile,v 1.47 2026/04/19 07:59:40 wiz Exp $

DISTNAME=		mkfontscale-1.2.4
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X11 Scalable Font Index Generator

USE_TOOLS+=		pkg-config
USE_FEATURES+=		vsnprintf

MESON_ARGS+=		-Dbzip2=true

CONFLICTS+=		mkfontdir-[0-9]*
SUPERSEDES+=		mkfontdir-[0-9]*

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
