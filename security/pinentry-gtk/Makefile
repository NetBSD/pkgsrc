# $NetBSD: Makefile,v 1.12 2014/12/10 02:27:43 mef Exp $
#

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-gtk-/}
PKGREVISION=		1
COMMENT=		Applications for entering PINs or Passphrases, gtk enabled

.include		"../../security/pinentry/Makefile.common"

CONFIGURE_ARGS+=	--enable-pinentry-gtk
CONFIGURE_ARGS+=	--disable-pinentry-curses
#CONFIGURE_ARGS+=	--disable-fallback-curses
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-qt4

INSTALL_DIRS=		gtk

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/gtk/buildlink3.mk"
#.include "../../security/libgpg-error/buildlink3.mk"
#.include "../../security/libksba/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
