# $NetBSD: Makefile,v 1.4 2020/08/17 20:20:00 leot Exp $

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-fltk-/}
PKGREVISION=		1
COMMENT=		Applications for entering PINs or Passphrases, FLTK enabled

.include		"../../security/pinentry/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/distinfo
USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
#CONFIGURE_ARGS+=	--disable-fallback-curses
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-libsecret

INSTALL_DIRS=		fltk

.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
