# $NetBSD: Makefile,v 1.2 2006/02/26 17:01:25 joerg Exp $
#

DISTNAME=		libdnsres-0.1a
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.monkey.org/~provos/

MAINTAINER=		adrianp@NetBSD.org
HOMEPAGE=		http://www.monkey.org/~provos/
COMMENT=		Non-blocking thread-safe API for resolving DNS names

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
