# $NetBSD: Makefile,v 1.1.1.1 2002/12/21 23:25:18 jmmv Exp $
#

DISTNAME=	sweep-0.5.13
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sweep/}

MAINTAINER=	jmmv@netbsd.org
HOMEPAGE=	http://sweep.sourceforge.net/
COMMENT=	Full-featured digital sound editor

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
.include "../../audio/mad/buildlink2.mk"
.include "../../audio/Speex/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../databases/tdb/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
