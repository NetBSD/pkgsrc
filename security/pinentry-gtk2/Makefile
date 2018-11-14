# $NetBSD: Makefile,v 1.46 2018/11/14 22:22:21 kleink Exp $

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-gtk2-/}
PKGREVISION=		4
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
