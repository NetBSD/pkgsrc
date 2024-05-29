# $NetBSD: Makefile,v 1.131 2024/05/29 16:34:25 adam Exp $

DISTNAME=	gvfs-1.6.7
PKGREVISION=	68
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/1.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Userspace virtual filesystem
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		intltool gmake pkg-config msgfmt
CONFIGURE_ARGS+=	--enable-http
CONFIGURE_ARGS+=	--disable-bash-completion

BUILDLINK_TRANSFORM+=	rm:-DG_DISABLE_DEPRECATED

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang) || ${CC_VERSION:Mgcc-[6-9]*} || ${CC_VERSION:Mgcc-1[0-9].*}
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
.else
CFLAGS.SunOS+=		-D_XOPEN_SOURCE=500 -D__EXTENSIONS__
.endif

.include "options.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.23.4
.include "../../devel/glib2/modules.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../security/libgnome-keyring/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
