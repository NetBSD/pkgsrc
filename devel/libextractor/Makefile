# $NetBSD: Makefile,v 1.54 2012/10/02 17:10:48 tron Exp $

DISTNAME=	libextractor-0.5.20c
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	http://gnunet.org/libextractor/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gnunet.org/libextractor/
COMMENT=	Metadata extractor for various file data types

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
INFO_FILES=		yes
PTHREAD_OPTS+=		require

CONFLICTS=		csound-{bath,dev}-*	# bin/extract

# This package requires dlopen, so save on space by skipping non-PIC libs
SHLIBTOOL_OVERRIDE=	# empty

DEPENDS+= ImageMagick-[0-9]*:../../graphics/ImageMagick

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
