# $NetBSD: Makefile,v 1.5 2022/08/11 05:09:13 gutteridge Exp $

PKGNAME=	${DISTNAME:S/pinentry-/pinentry-gnome3-/}
PKGREVISION=	1
COMMENT=	Applications for entering PINs or Passphrases, GNOME 3 enabled

.include "../../security/pinentry/Makefile.common"

USE_TOOLS+=		pkg-config
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-pinentry-fltk
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-libsecret
CONFIGURE_ARGS+=	--enable-pinentry-gnome3

INSTALL_DIRS=		gnome3

.include "../../security/gcr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
