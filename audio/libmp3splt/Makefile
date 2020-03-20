# $NetBSD: Makefile,v 1.16 2020/03/20 11:57:22 nia Exp $
#

DISTNAME=	libmp3splt-0.9.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://mp3splt.sourceforge.net/
COMMENT=	Split mp3, ogg vorbis and FLAC without decoding
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

LIBS.SunOS+=		-lresolv

CONFIGURE_ARGS+=	--with-ltdl-include=${BUILDLINK_PREFIX.libltdl}/include
CONFIGURE_ARGS+=	--with-ltdl-lib=${BUILDLINK_PREFIX.libltdl}/lib
CONFIGURE_ARGS+=	--disable-doxygen_doc

.include "options.mk"

.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
