# $NetBSD: Makefile,v 1.36 2007/01/07 12:25:52 wiz Exp $
#

DISTNAME=	sweep-0.8.3
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sweep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.metadecks.org/software/sweep/
COMMENT=	Full-featured digital sound editor

USE_DIRS+=		gnome1-1.5
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-oggtest
CONFIGURE_ARGS+=	--disable-vorbistest

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
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
