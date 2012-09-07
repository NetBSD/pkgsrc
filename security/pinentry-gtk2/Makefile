# $NetBSD: Makefile,v 1.16 2012/09/07 19:17:28 adam Exp $
#

DISTNAME=		pinentry-0.8.2
PKGNAME=		pinentry-gtk2-0.8.2
PKGREVISION=		1
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/pinentry/
COMMENT=		Applications for entering PINs or Passphrases

PATCHDIR=		${.CURDIR}/../../security/pinentry/patches
DISTINFO_FILE=		${.CURDIR}/../../security/pinentry/distinfo
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--enable-pinentry-gtk2
CONFIGURE_ARGS+=	--disable-pinentry-curses
#CONFIGURE_ARGS+=	--disable-fallback-curses
CONFIGURE_ARGS+=	--disable-pinentry-gtk
CONFIGURE_ARGS+=	--disable-pinentry-qt
CONFIGURE_ARGS+=	--disable-pinentry-qt4

INFO_FILES=		yes

INSTALL_DIRS=		gtk+-2

BUILDLINK_API_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
#.include "../../security/libgpg-error/buildlink3.mk"
#.include "../../security/libksba/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
