# $NetBSD: Makefile,v 1.120 2024/05/29 16:32:13 adam Exp $

DISTNAME=	libextractor-1.13
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=libextractor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gnu.org/s/libextractor/
COMMENT=	Metadata extractor for various file data types
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt msgmerge pkg-config xgettext
GNU_CONFIGURE=		yes
INFO_FILES=		yes
PTHREAD_OPTS+=		require

CONFLICTS=		csound-{bath,dev}-[0-9]*	# bin/extract

# This package requires dlopen, so save on space by skipping non-PIC libs
SHLIBTOOL_OVERRIDE=	# empty

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libsmf/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/mp4v2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../www/tidy/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
