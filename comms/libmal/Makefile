# $NetBSD: Makefile,v 1.1.1.1 2004/04/19 14:01:46 markd Exp $

DISTNAME=		libmal-0.40
CATEGORIES=		comms
MASTER_SITES=		http://jasonday.home.att.net/code/libmal/

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://jasonday.home.att.net/code/libmal/
COMMENT=		MAL convenience library

CONFLICTS+=		malsync-[0-9]*

USE_BUILDLINK3=		# defined
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		# defined

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-pilot-prefix=${BUILDLINK_PREFIX.pilot-link-libs}
CPPFLAGS+=		-D__unix__=1

.include "../../comms/pilot-link-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
