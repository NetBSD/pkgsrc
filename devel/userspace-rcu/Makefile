# $NetBSD: Makefile,v 1.1 2012/09/30 22:06:17 pettai Exp $
#

DISTNAME=	userspace-rcu-0.7.3
CATEGORIES=	devel
MASTER_SITES=	http://lttng.org/files/urcu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://lttng.org/urcu
COMMENT=	Userspace RCU (Read Copy Update)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

# liburcu requires TLS support, thus,
# only NetBSD-6 or later is supported
NOT_FOR_PLATFORM=	NetBSD-[0-5]*-*

PKGCONFIG_OVERRIDE+=	liburcu-bp.pc.in
PKGCONFIG_OVERRIDE+=	liburcu-cds.pc.in
PKGCONFIG_OVERRIDE+=	liburcu-mb.pc.in
PKGCONFIG_OVERRIDE+=	liburcu-qsbr.pc.in
PKGCONFIG_OVERRIDE+=	liburcu-signal.pc.in
PKGCONFIG_OVERRIDE+=	liburcu.pc.in

.include "../../mk/bsd.pkg.mk"
