# $NetBSD: Makefile,v 1.92 2024/05/29 16:33:54 adam Exp $

DISTNAME=	gupnp-1.6.6
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GUPnP
COMMENT=	Framework for UPnP devices
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=	pkg-config

LDFLAGS.SunOS+=	-lsocket

REPLACE_PYTHON=	tools/gupnp-binding-tool

PKGCONFIG_OVERRIDE+=		output/meson-private/gupnp-1.6.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/libgupnp
# for Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/libgupnp

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS:M*BSD} || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
pre-configure:
	cp ${FILESDIR}/uuid.pc ${BUILDLINK_DIR}/lib/pkgconfig/
.else
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../archivers/xz/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.58.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/py-gi-docgen/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
