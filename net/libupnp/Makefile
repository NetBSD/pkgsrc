# $NetBSD: Makefile,v 1.9 2008/01/03 12:32:34 obache Exp $
#

DISTNAME=		libupnp-1.6.3
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

BUILDLINK_TRANSFORM+=	rm:-lcompat

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=		check

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
