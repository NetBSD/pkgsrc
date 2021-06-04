# $NetBSD: Makefile,v 1.28 2021/06/04 18:56:40 adam Exp $

DISTNAME=	libupnp-1.14.7
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
PKGCONFIG_OVERRIDE+=	libupnp.pc.in
TEST_TARGET=		check

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
