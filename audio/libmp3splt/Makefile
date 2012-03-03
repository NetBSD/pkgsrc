# $NetBSD: Makefile,v 1.10 2012/03/03 00:12:41 wiz Exp $
#

DISTNAME=	libmp3splt-0.7
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mp3splt/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://mp3splt.sourceforge.net/
COMMENT=	Utility library for MP3 splitting/manipulation
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
