# $NetBSD: Makefile,v 1.1.1.1 2009/08/02 11:24:06 drochner Exp $
#

DISTNAME=	gssdp-0.6.4
CATEGORIES=	net
MASTER_SITES=	http://www.gupnp.org/sources/gssdp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gupnp.org/
COMMENT=	SSDP library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
PKG_DESTDIR_SUPPORT= user-destdir

PKGCONFIG_OVERRIDE+=	gssdp-1.0.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
