# $NetBSD: Makefile,v 1.61 2024/03/20 15:46:38 adam Exp $

PKGNAME=	${DISTNAME:S/pinentry-/pinentry-gtk2-/}
COMMENT=	Applications for entering PINs or Passphrases, GTK+ enabled

.include "../../security/pinentry/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--disable-libsecret
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-pinentry-fltk
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-qt5
CONFIGURE_ARGS+=	--enable-pinentry-gtk2

INSTALL_DIRS=		gtk+-2

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
