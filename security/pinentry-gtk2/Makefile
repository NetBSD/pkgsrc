# $NetBSD: Makefile,v 1.48 2019/07/21 22:25:40 wiz Exp $

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-gtk2-/}
PKGREVISION=		6
COMMENT=		Applications for entering PINs or Passphrases, GTK+ enabled

.include		"../../security/pinentry/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--enable-pinentry-gtk2
CONFIGURE_ARGS+=        --disable-pinentry-qt
CONFIGURE_ARGS+=        --disable-pinentry-curses
CONFIGURE_ARGS+=        --disable-pinentry-emacs
#CONFIGURE_ARGS+=       --disable-fallback-curses
CONFIGURE_ARGS+=        --disable-pinentry-gnome3
CONFIGURE_ARGS+=        --disable-pinentry-fltk
CONFIGURE_ARGS+=        --disable-libsecret

INSTALL_DIRS=		gtk+-2

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
