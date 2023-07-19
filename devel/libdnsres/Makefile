# $NetBSD: Makefile,v 1.23 2023/07/19 15:11:51 nia Exp $
#

DISTNAME=		libdnsres-0.1a
PKGREVISION=		15
CATEGORIES=		devel
MASTER_SITES=		https://www.monkey.org/~provos/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.monkey.org/~provos/
COMMENT=		Non-blocking thread-safe API for resolving DNS names

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
MAKE_JOBS_SAFE=		NO

# Need -fPIC when compiling objects for shared libraries, even
# if PKGSRC_MKPIE is no.
CFLAGS+=		-fPIC

# uses event_once
BUILDLINK_API_DEPENDS.libevent+=	libevent>=0.9

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
