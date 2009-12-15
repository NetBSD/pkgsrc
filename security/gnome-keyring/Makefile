# $NetBSD: Makefile,v 1.51 2009/12/15 14:07:22 wiz Exp $

DISTNAME=	gnome-keyring-2.28.2
CATEGORIES=	security gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-keyring/2.28/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	GNOME password and secret manager

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnome-keyring
PKG_SUPPORTED_OPTIONS+=	hal
PKG_SUGGESTED_OPTIONS+=	hal
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif

USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

PKGCONFIG_OVERRIDE=	${WRKSRC}/gcr/gcr.pc.in
PKGCONFIG_OVERRIDE=	${WRKSRC}/library/gnome-keyring-1.pc.in
PKGCONFIG_OVERRIDE=	${WRKSRC}/gp11/gp11.pc.in

GCONF_SCHEMAS+=		gnome-keyring.schemas

CFLAGS.HPUX+=		-DMAP_ANON=MAP_ANONYMOUS

# Workaround a bug with NetBSD's openpam
# The bug is described in PR security/39313
#
CFLAGS.NetBSD+=		-DNO_STATIC_MODULES

# Workaround for Upstream Bug#562310.
# for more detail, see also PR#41475.
TOOLS_NOOP+=	gtkdoc-rebase

.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0

.include "../../devel/GConf/schemas.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
