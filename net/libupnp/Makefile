# $NetBSD: Makefile,v 1.6 2007/08/19 01:36:22 obache Exp $
#

DISTNAME=		libupnp-1.6.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://pupnp.sourceforge.net/
COMMENT=		Portable Universal Plug and Play (UPnP) SDK

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-documentation

PKGCONFIG_OVERRIDE+=	libupnp.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
