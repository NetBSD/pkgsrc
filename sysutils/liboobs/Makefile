# $NetBSD: Makefile,v 1.3 2009/07/22 09:01:47 wiz Exp $
#

DISTNAME=		liboobs-2.22.0
PKGREVISION=		1
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/liboobs/2.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Lightweight GObject based interface to system-tools-backends

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_OPTIONS_VAR=	PKG_OPTIONS.liboobs
PKG_SUPPORTED_OPTIONS+=	hal
PKG_SUGGESTED_OPTIONS+=	hal
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

.include "../../sysutils/system-tools-backends/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
