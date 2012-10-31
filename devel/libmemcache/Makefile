# $NetBSD: Makefile,v 1.7 2012/10/31 11:17:17 asau Exp $
#

DISTNAME=		libmemcache-1.4.0.b9
PKGNAME=		${DISTNAME:S/.b/beta/}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://people.freebsd.org/~seanc/libmemcache/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://people.freebsd.org/~seanc/libmemcache/
COMMENT=		C API for memcached

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CPPFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t
CXXFLAGS.SunOS+=	-Du_int16_t=uint16_t -Du_int32_t=uint32_t -Du_int64_t=uint64_t

.include "../../devel/sysexits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
