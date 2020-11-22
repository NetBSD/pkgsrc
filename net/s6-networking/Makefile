# $NetBSD: Makefile,v 1.2 2020/11/22 11:33:22 schmonz Exp $

DISTNAME=	s6-networking-2.3.2.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://skarnet.org/software/s6-networking/
COMMENT=	Suite of small networking utilities
LICENSE=	isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--enable-absolute-paths

.include "options.mk"

BUILDLINK_API_DEPENDS.skalibs+=skalibs>=2.9.3.0
.include "../../devel/skalibs/buildlink3.mk"
BUILDLINK_API_DEPENDS.execline+=execline>=2.6.1.1
.include "../../lang/execline/buildlink3.mk"
.include "../../net/s6-dns/buildlink3.mk"
.include "../../sysutils/s6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
