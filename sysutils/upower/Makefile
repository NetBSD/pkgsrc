# $NetBSD: Makefile,v 1.10 2017/09/08 06:28:35 wiz Exp $

DISTNAME=	upower-0.99.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://upower.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://upower.freedesktop.org
COMMENT=	Power management system message bus service
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config intltool xgettext msgmerge msgfmt

BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libintl-prefix=${BUILDLINK_PREFIX.gettext}

PKG_SYSCONFSUBDIR=	UPower
INSTALL_MAKE_FLAGS+=	configdir=${EGDIR} dbusconfdir=${EGDIR}
EGDIR=			${PREFIX}/share/examples/upower
CONF_FILES+=		${EGDIR}/UPower.conf ${PKG_SYSCONFDIR}/UPower.conf
CONF_FILES+=		${EGDIR}/org.freedesktop.UPower.conf \
			${PKG_SYSCONFBASE}/dbus-1/system.d/org.freedesktop.UPower.conf

PKGCONFIG_OVERRIDE+=	upower-glib.pc.in
USE_PKGLOCALEDIR=	yes

BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--no-as-needed:-Wl,-zrecord
BUILDLINK_TRANSFORM.SunOS+=	opt:-Wl,--as-needed:-Wl,-zignore

TEST_TARGET=	check

# with --nonet, xsltproc needs a helping hand finding some dtds
XSLTPROC_PATH+=	${LOCALBASE}/share/doc/dbus

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../mk/bsd.pkg.mk"
