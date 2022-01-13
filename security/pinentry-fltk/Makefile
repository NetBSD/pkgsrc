# $NetBSD: Makefile,v 1.6 2022/01/13 08:05:48 adam Exp $

PKGNAME=	${DISTNAME:S/pinentry-/pinentry-fltk-/}
COMMENT=	Applications for entering PINs or Passphrases, FLTK enabled

.include "../../security/pinentry/Makefile.common"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-libsecret
CONFIGURE_ARGS+=	--enable-pinentry-fltk

INSTALL_DIRS=		fltk

.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
