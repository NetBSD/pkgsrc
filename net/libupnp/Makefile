# $NetBSD: Makefile,v 1.30 2024/07/15 10:26:47 adam Exp $

DISTNAME=	libupnp-1.14.19
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pupnp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pupnp.sourceforge.io/
COMMENT=	Portable Universal Plug and Play (UPnP) SDK
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-samples
# The following options are strong recommendations from multimedia/gerbera:
CONFIGURE_ARGS+=	--disable-blocking-tcp-connections
CONFIGURE_ARGS+=	--enable-reuseaddr
PKGCONFIG_OVERRIDE+=	libupnp.pc.in
TEST_TARGET=		check

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
