# $NetBSD: Makefile,v 1.41 2020/01/18 21:50:44 jperkin Exp $

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-qt4-/}
PKGREVISION=		2
COMMENT=		Applications for entering PINs or Passphrases, qt4 enabled

.include		"../../security/pinentry/Makefile.common"

CONFIGURE_ARGS+=	--enable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
#CONFIGURE_ARGS+=	--disable-fallback-curses
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-fltk

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake

INSTALL_DIRS=		qt

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/qt4-libs/buildlink3.mk"
#.include "../../security/libgpg-error/buildlink3.mk"
#.include "../../security/libksba/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
