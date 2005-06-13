# $NetBSD: Makefile,v 1.4.2.1 2005/06/13 21:36:08 snj Exp $
#

DISTNAME=		libextractor-0.4.2
CATEGORIES=		devel
MASTER_SITES=		http://gnunet.org/libextractor/download/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://gnunet.org/libextractor/
COMMENT=		Metadata extractor for various file data types

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

CONFLICTS=		csound-{bath,dev}-*	# bin/extract

# This package requires dlopen, so save on space by skipping non-PIC libs
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
