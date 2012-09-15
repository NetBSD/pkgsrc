# $NetBSD: Makefile,v 1.16 2012/09/15 10:06:01 obache Exp $
#

DISTNAME=	gupnp-0.13.3
PKGREVISION=	10
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sites/all/files/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PKG_DESTDIR_SUPPORT= user-destdir

PKGCONFIG_OVERRIDE+=	gupnp-1.0.pc.in
REPLACE_PYTHON=	tools/gupnp-binding-tool

.include "../../mk/bsd.prefs.mk"

.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly" || ${OPSYS} == "Darwin"
pre-configure:
	cp ${FILESDIR}/uuid.pc ${BUILDLINK_DIR}/lib/pkgconfig/
.else
.include "../../devel/libuuid/buildlink3.mk"
.endif

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
