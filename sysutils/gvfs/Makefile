# $NetBSD: Makefile,v 1.143 2026/05/10 17:38:14 vins Exp $
#

DISTNAME=	gvfs-1.60.0
CATEGORIES?=	sysutils
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gvfs/${PKGVERSION_NOREV:S/./ /g:[1..2]:ts.}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/gvfs
COMMENT=	Userspace virtual filesystem
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

USE_PKGLOCALEDIR=	yes

.include "../../mk/compiler.mk"

CFLAGS.NetBSD+=	-DNETBSD_SOURCE	# string.h

.if !empty(PKGSRC_COMPILER:Mclang) || ${CC_VERSION:Mgcc-[6-9]*} || ${CC_VERSION:Mgcc-1[0-9].*}
CFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
.else
CFLAGS.SunOS+=	-D_XOPEN_SOURCE=500 -D__EXTENSIONS__
.endif

LDFLAGS.SunOS+=	-lsocket	# if_indextoname()

# Enforce some defaults to prevent PLIST issues witnessed in some environments.
MESON_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
		--localedir=${PKGLOCALEDIR}/locale

# Disable some options which currently have no support on pkgsrc,
# and are otherwise only available on Linux.
MESON_ARGS+=	-Dlogind=false \
		-Donedrive=false \
		-Dudisks2=false

# Disable systemd support by default, as we currently lack a way to check for
# builtin systemd on Linux.
MESON_ARGS+=	-Dsystemduserunitdir=no \
		-Dtmpfilesdir=no

# Generate man pages; requires docbook-xsl.
TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl
DOCBOOK_MANPAGE_XSL=	${PREFIX}/share/xsl/docbook/manpages/docbook.xsl
MESON_ARGS+=		-Dman=true

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	man/meson.build
SUBST_VARS.man+=	DOCBOOK_MANPAGE_XSL

.include "../../mk/bsd.fast.prefs.mk"

# Turn on some settings by default.

## afp://[user@]host[:port][/share]
##   Apple Filing Protocol.
MESON_ARGS+=	-Dafp=true

## archive://{URL-ENCODED-URI}
##   Access archive files.
MESON_ARGS+=	-Darchive=true
.include "../../archivers/libarchive/buildlink3.mk"

## burn://{DEVICE}
##   Virtual filesystem for file managers to help them implement burning
##   optical discs.
MESON_ARGS+=	-Dburn=true

## http://, https://
##   HTTP protocol support.
MESON_ARGS+=	-Dhttp=true
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"

## libgcrypt support.
MESON_ARGS+=    -Dgcrypt=true
.include "../../security/libgcrypt/buildlink3.mk"

## libusb interruption support: not available on DragonFly.
.if ${OPSYS} != "DragonFly"
.  include "../../devel/libusb1/buildlink3.mk"
MESON_ARGS+=    -Dlibusb=true
.else
MESON_ARGS+=    -Dlibusb=false
.endif

## nfs://{HOST}/{SHARE}
##   NFS v2 and v3 protocols.
MESON_ARGS+=	-Dnfs=true
.include "../../net/libnfs/buildlink3.mk"

## sftp://[user@]host[:port], ssh://[user@]host[:port]
##   SFTP protocol support.
MESON_ARGS+=	-Dsftp=true

## wsdd:///
##   Access Web Service Discovery Daemon.
MESON_ARGS+=	-Dwsdd=true

.include "options.mk"

.include "../../devel/glib2/modules.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
