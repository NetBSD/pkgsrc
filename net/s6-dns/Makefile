# $NetBSD: Makefile,v 1.1 2020/11/19 20:05:54 schmonz Exp $

DISTNAME=	s6-dns-2.3.3.0
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://www.skarnet.org/software/s6-dns/
COMMENT=	Suite of DNS client programs and libraries
LICENSE=	isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
