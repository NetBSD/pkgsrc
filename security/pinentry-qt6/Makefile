# $NetBSD: Makefile,v 1.3 2024/05/29 16:34:18 adam Exp $

PKGNAME=	${DISTNAME:S/pinentry-/pinentry-qt6-/}
PKGREVISION=	2
COMMENT=	Applications for entering PINs or Passphrases, Qt6 enabled
CONFLICTS=	pinentry-qt4-[0-9]*

.include "../../security/pinentry/Makefile.common"

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config gmake autoconf
FORCE_CXX_STD=		c++17
CONFIGURE_ARGS+=	--disable-libsecret
CONFIGURE_ARGS+=	--disable-pinentry-curses
CONFIGURE_ARGS+=	--disable-pinentry-emacs
CONFIGURE_ARGS+=	--disable-pinentry-efl
CONFIGURE_ARGS+=	--disable-pinentry-fltk
CONFIGURE_ARGS+=	--disable-pinentry-gnome3
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt5
CONFIGURE_ARGS+=	--enable-pinentry-qt
CONFIGURE_ENV+=		MOC6="${QTDIR}/libexec/moc"
CONFIGURE_ENV+=		RCC6="${QTDIR}/libexec/rcc"

INSTALL_DIRS=		qt

pre-configure:
	cd ${WRKSRC} && autoreconf -i -f

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
