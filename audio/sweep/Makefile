# $NetBSD: Makefile,v 1.16 2004/02/19 11:39:24 wiz Exp $
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

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest

CPPFLAGS+=		-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
