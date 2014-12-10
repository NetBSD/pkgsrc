# $NetBSD: Makefile,v 1.21 2014/12/10 02:27:44 mef Exp $
#

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-qt-/}
PKGREVISION=		2
COMMENT=		Applications for entering PINs or Passphrases, qt3 enabled

.include		"../../security/pinentry/Makefile.common"

CONFIGURE_ARGS+=	--enable-pinentry-qt
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-qt-includes=${BUILDLINK_PREFIX.qt3-libs}/qt3/include
CONFIGURE_ARGS+=	--with-qt-libraries=${BUILDLINK_PREFIX.qt3-libs}/qt3/lib
CONFIGURE_ARGS+=	--disable-pinentry-curses
#CONFIGURE_ARGS+=	--disable-fallback-curses
CONFIGURE_ARGS+=	--disable-pinentry-gtk
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt4

USE_LANGUAGES+=		c c++
USE_TOOLS+=		gmake

INSTALL_DIRS=		qt

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/qt3-libs/buildlink3.mk"
#.include "../../security/libgpg-error/buildlink3.mk"
#.include "../../security/libksba/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
