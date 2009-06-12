# $NetBSD: Makefile,v 1.5 2009/06/12 17:24:53 ahoka Exp $
#

DISTNAME=	gpac-0.4.5
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gpac/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gpac.sourceforge.net/
COMMENT=	Open source multimedia framework

PKG_DESTDIR_SUPPORT=	user-destdir

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
.include "../../graphics/jpeg/buildlink3.mk"
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
