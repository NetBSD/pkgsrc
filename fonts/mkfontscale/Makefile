# $NetBSD: Makefile,v 1.35 2015/01/17 09:12:53 wiz Exp $

DISTNAME=		mkfontscale-1.1.2
CATEGORIES=		fonts x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 Scalable Font Index Generator

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_FEATURES+=		vsnprintf

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1
CONFIGURE_ARGS+=	--with-bzip2

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
