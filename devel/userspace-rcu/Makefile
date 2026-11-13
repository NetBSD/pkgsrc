# $NetBSD: Makefile,v 1.21 2026/11/13 17:04:05 adam Exp $

DISTNAME=	userspace-rcu-0.15.7
CATEGORIES=	devel
MASTER_SITES=	https://lttng.org/files/urcu/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://liburcu.org/
COMMENT=	Userspace RCU (Read Copy Update)
LICENSE=	gnu-lgpl-v2.1

USE_CXX_FEATURES=	c++11
USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config bash:test
GNU_CONFIGURE=		yes
TEST_TARGET=		check

# liburcu requires thread local storage support; thus,
# only NetBSD-6 or later is supported.
NOT_FOR_PLATFORM=	NetBSD-[0-5].*-*

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
