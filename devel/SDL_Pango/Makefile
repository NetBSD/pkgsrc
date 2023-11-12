# $NetBSD: Makefile,v 1.40 2023/11/12 13:20:55 wiz Exp $

DISTNAME=	SDL_Pango-0.1.2
PKGREVISION=	32
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlpango/}

PATCHFILES+=	SDL_Pango-0.1.2-API-adds.patch
PATCH_SITES+=	http://zarb.org/~gc/t/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sdlpango.sourceforge.net/
COMMENT=	Connects the text rendering engine of GNOME 2.x. with SDL
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	SDL_Pango.pc.in

CONFIGURE_ARGS+=	--with-sdl-prefix=${BUILDLINK_PREFIX.SDL}

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
