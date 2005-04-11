# $NetBSD: Makefile,v 1.34 2005/04/11 21:45:57 tv Exp $

DISTNAME=	scummvm-0.7.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion

USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${LOCALBASE}

UNLIMIT_RESOURCES=	datasize

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
