# $NetBSD: Makefile,v 1.16 2013/01/07 13:20:57 gdt Exp $
#
# Attention: Update this only together with devel/dconf-editor
#

DISTNAME=	dconf-0.14.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf/0.14/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/dconf
COMMENT=	Backend for gsettings
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --disable-editor
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool msgfmt

# Upstream's makefiles have hardcoded warnings for newer gcc versions.
BUILDLINK_TRANSFORM+=	opt:-Wno-unused-but-set-variable:-Wno-unused-variable

PKGCONFIG_OVERRIDE+=	client/dconf.pc.in dbus-1/dconf-dbus-1.pc.in

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=   rm:-ldl
.endif

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

BUILDLINK_DEPMETHOD.vala= build
.include "../../lang/vala018/buildlink3.mk"
.include "../../devel/glib2/modules.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
