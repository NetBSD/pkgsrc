# $NetBSD: Makefile,v 1.2 2010/02/22 17:20:39 drochner Exp $
#

DISTNAME=		pinentry-0.7.6
PKGNAME=		pinentry-gtk-0.7.6
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/pinentry/
COMMENT=		Applications for entering PINs or Passphrases

PATCHDIR=		${.CURDIR}/../../security/pinentry/patches
DISTINFO_FILE=		${.CURDIR}/../../security/pinentry/distinfo
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--enable-pinentry-gtk
CONFIGURE_ARGS+=	--disable-pinentry-curses
#CONFIGURE_ARGS+=	--disable-fallback-curses
CONFIGURE_ARGS+=	--disable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-qt4

INFO_FILES=		yes

INSTALL_DIRS=		gtk

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/gtk/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
#.include "../../security/libgpg-error/buildlink3.mk"
#.include "../../security/libksba/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
