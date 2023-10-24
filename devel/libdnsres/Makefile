# $NetBSD: Makefile,v 1.24 2023/10/24 22:08:50 wiz Exp $
#

DISTNAME=		libdnsres-0.1a
PKGREVISION=		16
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
