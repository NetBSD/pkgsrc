# $NetBSD: Makefile,v 1.23 2023/11/12 13:21:14 wiz Exp $

PKGNAME=	elvis-x11-${VERSION}
PKGREVISION=	4
COMMENT=	Clone of vi with regex-search, hex-edit, HTML/LaTeX preview (X11)

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xft
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
USE_TOOLS+=		pkg-config

BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../editors/elvis/Makefile.common"
.include "../../mk/bsd.pkg.mk"
