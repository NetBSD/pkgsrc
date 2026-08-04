# $NetBSD: Makefile,v 1.24 2026/08/04 20:28:53 wiz Exp $

PKGNAME=	elvis-x11-${VERSION}
PKGREVISION=	4
COMMENT=	Clone of vi with regex-search, hex-edit, HTML/LaTeX preview (X11)

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xft
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
USE_TOOLS+=		pkg-config

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../editors/elvis/Makefile.common"
.include "../../mk/bsd.pkg.mk"
