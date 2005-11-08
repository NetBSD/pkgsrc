# $NetBSD: Makefile,v 1.2 2005/11/08 03:44:23 tv Exp $
#

DISTNAME=		libmemcache-1.4.0.b9
PKGNAME=		${DISTNAME:S/.b/beta/}
CATEGORIES=		devel
MASTER_SITES=		http://people.freebsd.org/~seanc/libmemcache/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@netbsd.org
HOMEPAGE=		http://people.freebsd.org/~seanc/libmemcache/
COMMENT=		C API for memcached

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
