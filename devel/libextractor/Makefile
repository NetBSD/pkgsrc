# $NetBSD: Makefile,v 1.73 2019/02/11 15:06:54 gdt Exp $

DISTNAME=	libextractor-1.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=libextractor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnu.org/s/libextractor/
COMMENT=	Metadata extractor for various file data types
LICENSE=	gnu-gpl-v3

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++03
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
INFO_FILES=		yes
PTHREAD_OPTS+=		require

CONFLICTS=		csound-{bath,dev}-[0-9]*	# bin/extract

# This package requires dlopen, so save on space by skipping non-PIC libs
SHLIBTOOL_OVERRIDE=	# empty

DEPENDS+= ImageMagick-[0-9]*:../../graphics/ImageMagick

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
