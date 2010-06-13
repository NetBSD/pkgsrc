# $NetBSD: Makefile,v 1.5 2010/06/13 22:45:09 wiz Exp $
#

DISTNAME=	gssdp-0.7.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/gssdp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	SSDP library
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PKG_DESTDIR_SUPPORT= user-destdir

PKGCONFIG_OVERRIDE+=	gssdp-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
