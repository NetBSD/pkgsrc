# $NetBSD: Makefile,v 1.4 2021/01/25 17:06:35 schmonz Exp $

DISTNAME=	execline-2.7.0.1
CATEGORIES=	lang shells
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPAGE=	https://skarnet.org/software/execline/
COMMENT=	The execline scripting language
LICENSE=	isc

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-sysdeps=${PREFIX}/lib/skalibs/sysdeps
CONFIGURE_ARGS+=	--with-lib=${PREFIX}/lib/skalibs
CONFIGURE_ARGS+=	--with-include=${PREFIX}/include

BUILDLINK_API_DEPENDS.skalibs+=		skalibs>=2.10.0.1
.include "../../devel/skalibs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
