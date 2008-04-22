# $NetBSD: Makefile,v 1.7 2008/04/22 18:06:09 tnn Exp $
#

DISTNAME=		libdnsres-0.1a
PKGREVISION=		4
CATEGORIES=		devel
MASTER_SITES=		http://www.monkey.org/~provos/

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://www.monkey.org/~provos/
COMMENT=		Non-blocking thread-safe API for resolving DNS names

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

# uses event_once
BUILDLINK_API_DEPENDS.libevent+=	libevent>=0.9

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
