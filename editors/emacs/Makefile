# $NetBSD: Makefile,v 1.91.2.1 2006/04/26 15:20:27 salo Exp $

DISTNAME=	emacs-${EMACSVERSION}a
PKGREVISION=	3
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor)

.include "../../editors/emacs/Makefile.common"

CONFLICTS+=	emacs-nox11-[0-9]*

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}

.include "../../graphics/xpm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-xpm
.include "../../graphics/jpeg/buildlink3.mk"
CONFIGURE_ARGS+=	--with-jpeg
.include "../../graphics/tiff/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tiff
# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_DEPENDS.libungif+=	libungif>=4.1.0.1
.include "../../graphics/libungif/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gif
.include "../../graphics/png/buildlink3.mk"
CONFIGURE_ARGS+=	--with-png

PKG_OPTIONS_VAR=        PKG_OPTIONS.emacs
PKG_OPTIONS_OPTIONAL_GROUPS= toolkit
PKG_OPTIONS_GROUP.toolkit= emacs-xaw3d motif
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.elif !empty(PKG_OPTIONS:Memacs-xaw3d)
.include "../../x11/Xaw3d/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.else
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.endif

.include "../../mk/bsd.pkg.mk"
