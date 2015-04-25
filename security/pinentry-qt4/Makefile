# $NetBSD: Makefile,v 1.32 2015/04/25 14:24:49 tnn Exp $
#

PKGNAME=		${DISTNAME:S/pinentry-/pinentry-qt4-/}
PKGREVISION=		1
COMMENT=		Applications for entering PINs or Passphrases, qt4 enabled

.include		"../../security/pinentry/Makefile.common"

CONFIGURE_ARGS+=	--enable-pinentry-qt4
CONFIGURE_ARGS+=	--with-qt-dir=${QTDIR:Q}
CONFIGURE_ARGS+=	--with-qt-includes=${BUILDLINK_PREFIX.qt4-libs}/qt4/include
CONFIGURE_ARGS+=	--with-qt-libraries=${BUILDLINK_PREFIX.qt4-libs}/qt4/lib
CONFIGURE_ARGS+=	--disable-pinentry-curses
#CONFIGURE_ARGS+=	--disable-fallback-curses
CONFIGURE_ARGS+=	--disable-pinentry-gtk
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt

USE_LANGUAGES+=		c c++
USE_TOOLS+=		pkg-config gmake

INSTALL_DIRS=		qt4

post-configure:
	cd $(WRKSRC)/qt4 && \
	$(QTDIR)/bin/moc pinentrydialog.h -o pinentrydialog.moc && \
	$(QTDIR)/bin/moc qsecurelineedit.h -o qsecurelineedit.moc

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/qt4-libs/buildlink3.mk"
#.include "../../security/libgpg-error/buildlink3.mk"
#.include "../../security/libksba/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
