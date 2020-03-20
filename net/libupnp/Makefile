# $NetBSD: Makefile,v 1.27 2020/03/20 20:46:40 joerg Exp $

DISTNAME=		libupnp-1.8.4
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pupnp/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pupnp.sourceforge.io/
COMMENT=		Portable Universal Plug and Play (UPnP) SDK
LICENSE=		modified-bsd

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libupnp.pc.in

TEST_TARGET=		check

CFLAGS.SunOS+=		-D_POSIX_PTHREAD_SEMANTICS

.include "options.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
