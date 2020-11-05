# $NetBSD: Makefile,v 1.8 2020/11/05 09:07:04 ryoon Exp $

DISTNAME=	gupnp-1.2.2
PKGNAME=	${DISTNAME:S/gupnp/gupnp12/}
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices (1.2 branch)
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

REPLACE_PYTHON=	tools/gupnp-binding-tool-1.2

PKGCONFIG_OVERRIDE+=		output/meson-private/gupnp-1.2.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/libgupnp

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
pre-configure:
	cp ${FILESDIR}/uuid.pc ${BUILDLINK_DIR}/lib/pkgconfig/
.else
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../archivers/xz/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.58.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.libsoup+=	libsoup>=2.48.0
.include "../../net/libsoup/buildlink3.mk"
.include "../../net/gssdp12/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
