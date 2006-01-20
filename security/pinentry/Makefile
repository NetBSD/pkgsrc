# $NetBSD: Makefile,v 1.9 2006/01/20 21:02:51 joerg Exp $
#

DISTNAME=		pinentry-0.7.1
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		ftp://ftp.gnupg.org/gcrypt/pinentry/

MAINTAINER=		shannonjr@NetBSD.org
HOMEPAGE=		ftp://ftp.gnupg.org/gcrypt/pinentry/
COMMENT=		Applications for entering PINs or Passphrases

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}

INFO_FILES=		pinentry.info

# XXX This usage of bsd.options.mk is wrong and has to be fixed.  The
# package has to be splitted into different packages, such as pinentry-gtk
# and pinentry-qt, so that the frontends can be built on their own and
# can be distributed in different binary packages.
PKG_OPTIONS_VAR=	PKG_OPTIONS.pinentry
PKG_SUPPORTED_OPTIONS=	gtk qt
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
PLIST_SUBST+=		USE_GTK=
.  include "../../x11/gtk/buildlink3.mk"
.else
PLIST_SUBST+=		USE_GTK='@comment '
.endif

.if !empty(PKG_OPTIONS:Mqt)
USE_TOOLS+=		gmake
PLIST_SUBST+=		USE_QT=
.  include "../../x11/qt3-libs/buildlink3.mk"
.else
PLIST_SUBST+=		USE_QT='@comment '
.endif

BUILDLINK_DEPENDS.libgpg-error+=	libgpg-error>=1.0.0

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libksba/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
