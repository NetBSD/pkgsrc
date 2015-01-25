# $NetBSD: Makefile,v 1.38 2015/01/25 08:15:34 wiz Exp $

DISTNAME=	gupnp-0.20.13
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gupnp/0.20/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	gupnp-1.0.pc.in
REPLACE_PYTHON=	tools/gupnp-binding-tool

TEST_TARGET=	check
#CFLAGS=-O0 -g
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
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.libsoup24+=	libsoup24>=2.48.0
.include "../../net/libsoup24/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
