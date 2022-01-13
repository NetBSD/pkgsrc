# $NetBSD: Makefile,v 1.4 2022/01/13 08:05:49 adam Exp $

PKGNAME=	${DISTNAME:S/pinentry-/pinentry-qt5-/}
COMMENT=	Applications for entering PINs or Passphrases, qt5 enabled
CONFLICTS=	pinentry-qt4-[0-9]*

.include "../../security/pinentry/Makefile.common"

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake autoconf
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-pinentry-fltk
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-libsecret
CONFIGURE_ARGS+=	--enable-pinentry-qt

INSTALL_DIRS=		qt

pre-configure:
	cd ${WRKSRC} && autoreconf -i -f

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
