# $NetBSD: Makefile,v 1.4 2009/06/12 17:24:53 ahoka Exp $
#

SVNREV=		629
DISTNAME=	fuppes-r${SVNREV}
PKGNAME=	${DISTNAME:S/r/0./}
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.invisible.ca/~jmcneill/distfiles/

MAINTAINER=	tech-multimedia@NetBSD.org
HOMEPAGE=	http://fuppes.ulrich-voelkel.de/
COMMENT=	Free UPnP Entertainment Service

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
USE_TOOLS+=	autoconf automake aclocal m4 autoreconf
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-video-transcoding

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-patch
SUBST_SED.version=	-e "s,UNKNOWN,${SVNREV},g"
SUBST_FILES.version=	version.sh
SUBST_MESSAGE.version=	Patching version script for non-SVN checkout builds.

pre-configure:
	cd ${WRKSRC} && autoreconf -i

BUILD_DEPENDS+=		gettext-m4>=0.14.6:../../devel/gettext-m4

.include "../../devel/pcre/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/twolame/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/simage/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/mpeg4ip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
