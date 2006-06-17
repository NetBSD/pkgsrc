# $NetBSD: Makefile,v 1.3 2006/06/17 19:07:10 rillig Exp $
#

DISTNAME=		libmemcache-1.4.0.b9
PKGNAME=		${DISTNAME:S/.b/beta/}
CATEGORIES=		devel
MASTER_SITES=		http://people.freebsd.org/~seanc/libmemcache/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://people.freebsd.org/~seanc/libmemcache/
COMMENT=		C API for memcached

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
