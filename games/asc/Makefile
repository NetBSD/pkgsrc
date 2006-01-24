# $NetBSD: Makefile,v 1.29 2006/01/24 07:33:34 wiz Exp $

DISTNAME=	asc-source+music-1.16.3.0
PKGNAME=	${DISTNAME:S/-source+music//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=asc-hq/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.asc-hq.org/
COMMENT=	Turn based strategy game

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CPPFLAGS.NetBSD+=	-D_UNICODE_BROKEN_

# ../weaponguide.cpp:1205: virtual memory exhausted
UNLIMIT_RESOURCES=	datasize

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDLmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/paragui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
