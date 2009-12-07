# $NetBSD: Makefile,v 1.60 2009/12/07 23:57:31 wiz Exp $

DISTNAME=	scummvm-1.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--prefix=${PREFIX}

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.1
UNLIMIT_RESOURCES=	datasize

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
