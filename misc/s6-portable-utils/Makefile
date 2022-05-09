# $NetBSD: Makefile,v 1.7 2022/05/09 14:54:30 schmonz Exp $

DISTNAME=	s6-portable-utils-2.2.4.0
CATEGORIES=	misc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://www.skarnet.org/software/s6-portable-utils/
COMMENT=	Tiny portable generic utilties
LICENSE=	isc

MANPAGES=		v2.2.4.0.1.tar.gz
SITES.${MANPAGES}=	${MASTER_SITE_GITHUB:=flexibeast/s6-portable-utils-man-pages/archive/}

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
