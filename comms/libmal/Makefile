# $NetBSD: Makefile,v 1.9 2007/01/26 01:37:09 markd Exp $

DISTNAME=		libmal-0.43
CATEGORIES=		comms
MASTER_SITES=		http://jasonday.home.att.net/code/libmal/

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://jasonday.home.att.net/code/libmal/
COMMENT=		MAL convenience library

CONFLICTS+=		malsync-[0-9]*

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pilot-prefix=${BUILDLINK_PREFIX.pilot-link-libs}
CPPFLAGS+=		-D__unix__=1
CPPFLAGS.Darwin+=	-DDARWIN

.include "../../comms/pilot-link-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
