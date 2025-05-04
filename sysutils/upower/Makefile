# $NetBSD: Makefile,v 1.26 2025/05/04 06:30:39 vins Exp $

DISTNAME=	upower-v1.90.9
PKGNAME=	${DISTNAME:S/v//}
CATEGORIES=	sysutils
MASTER_SITES=	https://gitlab.freedesktop.org/upower/upower/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://upower.freedesktop.org/
COMMENT=	Power management system message bus service
LICENSE=	gnu-gpl-v2

USE_CC_FEATURES=	c11
USE_TOOLS+=		pkg-config intltool gdbus-codegen \
			xgettext msgmerge msgfmt

USE_PKGLOCALEDIR=	yes

BUILD_DEFS+=	VARBASE PKG_SYSCONFBASE

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

PKG_SYSCONFSUBDIR=	UPower
EGDIR=			${PREFIX}/share/examples/upower
CONF_FILES+=		${EGDIR}/UPower.conf ${PKG_SYSCONFDIR}/UPower.conf
CONF_FILES+=		${EGDIR}/org.freedesktop.UPower.conf \
			${PKG_SYSCONFBASE}/dbus-1/system.d/org.freedesktop.UPower.conf

PKGCONFIG_OVERRIDE+=	upower-glib.pc.in

.include "../../mk/bsd.prefs.mk"

# Free/OpenBSD and Linux are officially supported.
# However, the Linux backend requires gudev, which we lack in pkgsrc.
.if ${OPSYS} == "OpenBSD" || ${OPSYS} == "FreeBSD"
MESON_ARGS+=	-Dos_backend=${LOWER_OPSYS}
.else
MESON_ARGS+=	-Dos_backend=dummy
.endif

MESON_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR} \
		--localedir=${PKGLOCALEDIR}/locale \
		-Dstatedir=${VARBASE} \
		-Dhistorydir=${VARBASE}/db/upower \
		-Degdir=${EGDIR} \
		-Dman=true \
		-Dgtk-doc=false \
		-Dudevrulesdir=disabled \
		-Dudevhwdbdir=disabled \
		-Dsystemdsystemunitdir=no \
		-Didevice=disabled

.include "options.mk"

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--as-needed
BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-as-needed
BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--no-as-needed:-Wl,-zrecord
BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--as-needed:-Wl,-zignore

# with --nonet, xsltproc needs a helping hand finding some dtds
XSLTPROC_PATH=	${PREFIX}/share/doc/dbus

# GNU msgfmt >=0.19.7 required to produce files of type: xml
BUILDLINK_API_DEPENDS.gettext-tools+= gettext-tools>=0.19.7
# Otherwise built-in msgfmt is used regardless of line above
USE_BUILTIN.gettext=    no
.include "../../devel/gettext-tools/buildlink3.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=   glib2>=2.66.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
