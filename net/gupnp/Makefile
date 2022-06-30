# $NetBSD: Makefile,v 1.76 2022/06/30 11:18:41 nia Exp $

DISTNAME=	gupnp-1.0.3
PKGREVISION=	17
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp/1.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices (1.0 branch)
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gupnp-1.0.pc.in
REPLACE_PYTHON=		tools/gupnp-binding-tool

TEST_TARGET=		check
#CFLAGS=		-O0 -g
#CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:Q}
#CONFIGURE_ARGS+=	--disable-shared
#CONFIGURE_ARGS+=	--enable-static

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
pre-configure:
	cp ${FILESDIR}/uuid.pc ${BUILDLINK_DIR}/lib/pkgconfig/
.else
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../archivers/xz/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.39.90
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/libsoup/buildlink3.mk"
BUILDLINK_API_DEPENDS.gssdp+=	gssdp>=0.14.15
.include "../../net/gssdp/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
