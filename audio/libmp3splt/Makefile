# $NetBSD: Makefile,v 1.11 2012/09/12 00:24:42 asau Exp $
#

DISTNAME=	libmp3splt-0.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://mp3splt.sourceforge.net/
COMMENT=	Utility library for MP3 splitting/manipulation
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

LIBS.SunOS+=		-lresolv

FIND_PREFIX:=   LTDLDIR=libltdl
.include "../../mk/find-prefix.mk"

CONFIGURE_ARGS+=	--with-ltdl-include=${LTDLDIR}/include
CONFIGURE_ARGS+=	--with-ltdl-lib=${LTDLDIR}/lib

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
