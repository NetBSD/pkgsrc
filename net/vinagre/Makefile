# $NetBSD: Makefile,v 1.119 2023/11/14 14:02:41 wiz Exp $

DISTNAME=	vinagre-3.6.2
PKGREVISION=	75
CATEGORIES=	net x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vinagre/3.6/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.gnome.org/vinagre/
COMMENT=	VNC client for GNOME
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool pkg-config itstool
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LANGUAGES=	c99 c++

USE_PKGLOCALEDIR=	yes

CFLAGS.SunOS+=	-D__EXTENSIONS__
LDFLAGS.SunOS+=	-lnsl

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || ${CC_VERSION:Mgcc-[6-9].*} || ${CC_VERSION:Mgcc-1[0-9].*}
CFLAGS+=	-Wno-error=format-nonliteral
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.vinagre
PKG_SUPPORTED_OPTIONS=	avahi telepathy
.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Mavahi)
CONFIGURE_ARGS+= --without-avahi
.else
.include "../../net/avahi/buildlink3.mk"
.endif
PLIST_VARS+= telepathy
.if !empty(PKG_OPTIONS:Mtelepathy)
CONFIGURE_ARGS+= --with-telepathy
.include "../../chat/telepathy-glib/buildlink3.mk"
PLIST.telepathy= yes
.else
CONFIGURE_ARGS+= --without-telepathy
.endif

# Interface conflicts with glibc's version
CONFIGURE_ARGS.NetBSD+=	ac_cv_func_ptsname_r=no

.include "../../databases/shared-mime-info/mimedb.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.28.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/gtk-vnc/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.0.3
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
