# $NetBSD: Makefile,v 1.37 2015/09/30 19:56:42 wiz Exp $

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-gtk2-/}
COMMENT=		Applications for entering PINs or Passphrases, gtk2 enabled

.include		"../../security/pinentry/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--enable-pinentry-gtk2
CONFIGURE_ARGS+=        --disable-pinentry-qt4
CONFIGURE_ARGS+=        --disable-pinentry-curses
CONFIGURE_ARGS+=        --disable-pinentry-emacs
#CONFIGURE_ARGS+=       --disable-fallback-curses
CONFIGURE_ARGS+=        --disable-pinentry-gnome3

INSTALL_DIRS=		gtk+-2

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
