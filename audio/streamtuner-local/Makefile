# $NetBSD: Makefile,v 1.14 2004/10/03 00:13:09 tv Exp $
#

DISTNAME=	streamtuner-local-0.4.0
PKGREVISION=	1
CATEGORIES=	audio www
MASTER_SITES=	http://savannah.nongnu.org/download/streamtuner/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/streamtuner/
COMMENT=	Streamtuner plugin providing access to your local MP3 repository

USE_BUILDLINK3=	    yes
USE_LIBTOOL=	    yes
USE_PKGLOCALEDIR=   yes
GNU_CONFIGURE=	    yes
USE_GNU_TOOLS+=	    make
USE_X11=	    yes

SHLIBTOOL_OVERRIDE=	libtool

CONFIGURE_ARGS+=	--enable-id3
CONFIGURE_ARGS+=	--with-id3tag=${BUILDLINK_DIR}/lib

.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/streamtuner/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
