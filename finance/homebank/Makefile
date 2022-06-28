# $NetBSD: Makefile,v 1.30 2022/06/28 11:33:52 wiz Exp $

DISTNAME=	homebank-5.5.5
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	http://homebank.free.fr/public/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://homebank.free.fr/
COMMENT=	HomeBank is to manage your personal accounts at home
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config perl intltool gmake msgfmt

PKG_OPTIONS_VAR=	PKG_OPTIONS.homebank
PKG_SUPPORTED_OPTIONS=	libofx
PKG_SUGGESTED_OPTIONS=	libofx

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mlibofx)
BUILDLINK_API_DEPENDS.libofx+=	libofx>=0.8.0
.include "../../finance/libofx/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-libofx
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
