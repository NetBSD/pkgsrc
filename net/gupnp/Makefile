# $NetBSD: Makefile,v 1.1.1.1 2009/08/02 11:35:26 drochner Exp $
#

DISTNAME=	gupnp-0.12.8
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/gupnp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	Framework for UPnP devices

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PKG_DESTDIR_SUPPORT= user-destdir

PKGCONFIG_OVERRIDE+=	gupnp-1.0.pc.in
REPLACE_PYTHON=	tools/gupnp-binding-tool

.include "../../lang/python/application.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../net/gssdp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
