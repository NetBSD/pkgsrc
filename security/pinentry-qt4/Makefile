# $NetBSD: Makefile,v 1.29 2014/02/12 23:18:35 tron Exp $
#

DISTNAME=		pinentry-0.8.3
PKGNAME=		pinentry-qt4-0.8.3
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/pinentry/
COMMENT=		Applications for entering PINs or Passphrases

PATCHDIR=		${.CURDIR}/../../security/pinentry/patches
DISTINFO_FILE=		${.CURDIR}/../../security/pinentry/distinfo

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
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
INFO_FILES=		yes

INSTALL_DIRS=		qt4

post-configure:
	cd $(WRKSRC)/qt4 && \
	$(QTDIR)/bin/moc pinentrydialog.h -o pinentrydialog.moc && \
	$(QTDIR)/bin/moc qsecurelineedit.h -o qsecurelineedit.moc

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
#.include "../../security/libgpg-error/buildlink3.mk"
#.include "../../security/libksba/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
