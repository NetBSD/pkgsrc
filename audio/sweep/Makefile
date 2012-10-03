# $NetBSD: Makefile,v 1.54.2.1 2012/10/03 12:06:42 spz Exp $
#

DISTNAME=	sweep-0.9.3
PKGREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sweep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.metadecks.org/software/sweep/
COMMENT=	Full-featured digital sound editor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest
# XXX this doesn't work
#CONFIGURE_ARGS+=	--disable-alsa

CPPFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:Q}

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/speex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/tdb/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
