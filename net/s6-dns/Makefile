# $NetBSD: Makefile,v 1.10 2023/11/23 18:51:33 schmonz Exp $

DISTNAME=	s6-dns-2.3.7.0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.skarnet.org/software/s6-dns/
COMMENT=	Suite of DNS client programs and libraries
LICENSE=	isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

BUILDLINK_API_DEPENDS.skalibs+=	skalibs>=2.14.0.1
.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
