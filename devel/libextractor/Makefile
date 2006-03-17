# $NetBSD: Makefile,v 1.10.2.1 2006/03/17 11:25:04 salo Exp $

DISTNAME=	libextractor-0.5.10
CATEGORIES=	devel
MASTER_SITES=	http://gnunet.org/libextractor/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gnunet.org/libextractor/
COMMENT=	Metadata extractor for various file data types

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

CONFLICTS=		csound-{bath,dev}-*	# bin/extract

# This package requires dlopen, so save on space by skipping non-PIC libs
SHLIBTOOL_OVERRIDE+=	${WRKSRC}/libtool

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
