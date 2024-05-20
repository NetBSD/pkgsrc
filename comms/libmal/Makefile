# $NetBSD: Makefile,v 1.17 2024/05/20 13:03:49 gdt Exp $

DISTNAME=		libmal-0.44
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		https://www.jlogday.com/code/libmal/archive/

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
