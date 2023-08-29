# $NetBSD: Makefile,v 1.84 2023/08/29 19:51:59 adam Exp $

DISTNAME=	gupnp-1.6.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices (1.2 branch)
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

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
