# $NetBSD: Makefile,v 1.5 2022/08/11 05:09:07 gutteridge Exp $

DISTNAME=		MP4Tools-3.8
PKGNAME=		${DISTNAME:tl}
PKGREVISION=		3
CATEGORIES=		multimedia x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mp4joiner/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.mp4joiner.org/
COMMENT=		Join and split MP4 files
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake msgfmt msgmerge xgettext
USE_LANGUAGES=		c c++

GNU_CONFIGURE_WX_VERSION=	no
CONFIGURE_ENV+=          ac_cv_path_FFMPEG_PATH=${PREFIX}/bin/ffmpeg4

.include "../../graphics/wxsvg/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/gpac/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
