# $NetBSD: Makefile,v 1.2 2021/01/11 18:17:12 schmonz Exp $

DISTNAME=	s6-2.10.0.0
CATEGORIES=	sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://skarnet.org/software/s6/
COMMENT=	The s6 supervision suite
LICENSE=	isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/execline
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

.include "../../devel/skalibs/buildlink3.mk"
.include "../../lang/execline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
