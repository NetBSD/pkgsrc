# $NetBSD: Makefile,v 1.4 2021/01/25 17:07:04 schmonz Exp $

DISTNAME=	s6-2.10.0.1
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

BUILDLINK_API_DEPENDS.skalibs+=		skalibs>=2.10.0.1
.include "../../devel/skalibs/buildlink3.mk"
.include "../../lang/execline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
