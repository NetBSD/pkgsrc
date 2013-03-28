# $NetBSD: Makefile,v 1.21 2013/03/28 22:22:46 jperkin Exp $
#

DISTNAME=		libupnp-1.6.18
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://pupnp.sourceforge.net/
COMMENT=		Portable Universal Plug and Play (UPnP) SDK
LICENSE=		modified-bsd

USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-documentation

PKGCONFIG_OVERRIDE+=	libupnp.pc.in

TEST_TARGET=		check

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
