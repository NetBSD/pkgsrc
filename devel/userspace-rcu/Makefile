# $NetBSD: Makefile,v 1.13 2020/04/29 19:44:49 maya Exp $
#

DISTNAME=	userspace-rcu-0.8.7
CATEGORIES=	devel
MASTER_SITES=	http://lttng.org/files/urcu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://lttng.org/urcu
COMMENT=	Userspace RCU (Read Copy Update)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	liburcu-bp.pc.in
PKGCONFIG_OVERRIDE+=	liburcu-cds.pc.in
PKGCONFIG_OVERRIDE+=	liburcu-mb.pc.in
PKGCONFIG_OVERRIDE+=	liburcu-qsbr.pc.in
PKGCONFIG_OVERRIDE+=	liburcu-signal.pc.in
PKGCONFIG_OVERRIDE+=	liburcu.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
