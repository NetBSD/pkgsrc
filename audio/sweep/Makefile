# $NetBSD: Makefile,v 1.13 2003/12/08 14:41:38 wiz Exp $
#

DISTNAME=	sweep-0.8.2
PKGREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sweep/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://sweep.sourceforge.net/
COMMENT=	Full-featured digital sound editor

DEPENDS+=	gnome1-dirs>=1.0:../../misc/gnome1-dirs

BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest

CPPFLAGS+=		-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS}

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/libsamplerate/buildlink2.mk"
.include "../../audio/libsndfile/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/speex/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/tdb/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
