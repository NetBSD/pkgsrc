# $NetBSD: Makefile,v 1.59 2023/11/12 13:23:25 wiz Exp $

PKGNAME=	${DISTNAME:S/pinentry-/pinentry-gtk2-/}
PKGREVISION=	4
COMMENT=	Applications for entering PINs or Passphrases, GTK+ enabled

.include "../../security/pinentry/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--enable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-pinentry-fltk
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-libsecret

INSTALL_DIRS=		gtk+-2

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
