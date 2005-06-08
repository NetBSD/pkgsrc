# $NetBSD: Makefile,v 1.86 2005/06/08 14:39:40 markd Exp $

DISTNAME=	emacs-${EMACSVERSION}a
PKGREVISION=	1
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor)

.include "../../editors/emacs/Makefile.common"

CONFLICTS+=	emacs-nox11-[0-9]*

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-x-toolkit=athena
CONFIGURE_ARGS+=	--srcdir=${WRKSRC}

.include "../../graphics/xpm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xpm
.include "../../graphics/jpeg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jpeg
.include "../../graphics/tiff/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tiff
# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_DEPENDS.libungif=	libungif>=4.1.0.1
.include "../../graphics/libungif/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gif
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=	--with-png

PKG_OPTIONS_VAR=        PKG_OPTIONS.emacs
PKG_SUPPORTED_OPTIONS=  emacs-xaw3d
PKG_OPTIONS_LEGACY_VARS+= EMACS_USE_XAW3D:emacs-xaw3d
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Memacs-xaw3d)
.include "../../x11/Xaw3d/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
