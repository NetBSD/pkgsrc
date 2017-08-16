# $NetBSD: Makefile,v 1.15 2017/08/16 20:45:32 wiz Exp $

DISTNAME=		libmal-0.44
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		http://www.jlogday.com/code/libmal/archive/

MAINTAINER=		markd@NetBSD.org
#HOMEPAGE=		http://jasonday.home.att.net/code/libmal/
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
