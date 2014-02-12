# $NetBSD: Makefile,v 1.18 2014/02/12 23:17:48 tron Exp $
#

DISTNAME=		libdnsres-0.1a
PKGREVISION=		11
CATEGORIES=		devel
MASTER_SITES=		http://www.monkey.org/~provos/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.monkey.org/~provos/
COMMENT=		Non-blocking thread-safe API for resolving DNS names

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
MAKE_JOBS_SAFE=		NO

# uses event_once
BUILDLINK_API_DEPENDS.libevent+=	libevent>=0.9

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
