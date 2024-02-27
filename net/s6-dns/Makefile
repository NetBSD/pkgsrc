# $NetBSD: Makefile,v 1.12 2024/02/27 04:36:50 charlotte Exp $

DISTNAME=	s6-dns-2.3.7.1
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
