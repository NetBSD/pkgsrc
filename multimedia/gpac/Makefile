# $NetBSD: Makefile,v 1.17 2011/11/16 01:33:17 sbd Exp $
#

DISTNAME=	gpac-0.4.5
PKGREVISION=	11
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gpac.sourceforge.net/
COMMENT=	Open source multimedia framework
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/gpac
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
# not really GNU configure, but close enough
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-wx

.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
# doesn't work yet
#.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
